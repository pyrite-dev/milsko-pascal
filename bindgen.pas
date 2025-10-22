program bindgen;

uses
	DOM,
	XMLRead,
	FGL,
	Sysutils;

type
	TPropDict = specialize TFPGMap<String, TDOMElement>;

var
	XML : TXMLDocument;
	Prop : TPropDict;
	StructOut, EnumOut, PropOut, ConstOut, FuncDefOut, VarOut : TextFile;

function PropToString(PropName : String) : String;
begin
	PropToString := '';

	if Prop[PropName].NodeName = 'integer' then PropToString := 'I';
	if Prop[PropName].NodeName = 'string' then PropToString := 'S';
	if Prop[PropName].NodeName = 'pixmap' then PropToString := 'V';
	if (Prop[PropName].NodeName = 'struct') and (Prop[PropName].GetAttribute('pointer') = 'yes') then PropToString := 'V';
	if Prop[PropName].NodeName = 'handler' then PropToString := 'C';

	PropToString := PropToString + PropName;
end;

function TypeToPascal(Node : TDOMNode) : String;
begin
	TypeToPascal := '';
	if TDOMElement(Node).GetAttribute('pointer') = 'yes' then TypeToPascal := TypeToPascal + 'P';
	if Node.NodeName = 'struct' then TypeToPascal := TypeToPascal + String(TDOMElement(Node).GetAttribute('defname'));
	if (Node.NodeName = 'integer') and (TDOMElement(Node).GetAttribute('unsigned') = 'yes') then TypeToPascal := TypeToPascal + 'Cardinal';
	if (Node.NodeName = 'integer') and not(TDOMElement(Node).GetAttribute('unsigned') = 'yes') then TypeToPascal := TypeToPascal + 'Integer';
	if Node.NodeName = 'string' then TypeToPascal := TypeToPascal + 'PChar';
	if Node.NodeName = 'class' then TypeToPascal := TypeToPascal + 'MwClass';
	if Node.NodeName = 'pointer' then TypeToPascal := TypeToPascal + 'Pointer';
	if Node.NodeName = 'widget' then TypeToPascal := TypeToPascal + 'MwWidget';
	if Node.NodeName = 'pixmap' then TypeToPascal := TypeToPascal + 'MwLLPixmap';
	if Node.NodeName = 'handler' then TypeToPascal := TypeToPascal + 'MwUserHandler';
	if Node.NodeName = 'error_handler' then TypeToPascal := TypeToPascal + 'MwErrorHandler';
end;

procedure ScanProperties();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('properties');
	
	WriteLn(PropOut, 'const');
	
	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		WriteLn('Property ' + TDOMElement(Child).GetAttribute('name'));

		Prop[String(TDOMElement(Child).GetAttribute('name'))] := TDOMElement(Child);

		WriteLn(PropOut, '	MwN' + String(TDOMElement(Child).GetAttribute('name')) + ' : PChar = ''' + PropToString(String(TDOMElement(Child).GetAttribute('name'))) + ''';');

		Child := Child.NextSibling;
	end;
	List.Free();
end;

function IntegerTrans(Content : String) : String;
begin
	IntegerTrans := Content;
	if (Length(Content) > 2) and (Copy(Content, 1, 2) = '0x') then
	begin
		IntegerTrans := '$' + Copy(Content, 3);
	end;
end;

procedure ScanEnumeration(Node : TDOMNode);
var
	Child : TDOMNode;
	Content : String;
	EnumName : String;
begin
	EnumName := String(TDOMElement(Node).GetAttribute('name'));

	WriteLn('Enumeration ' + EnumName);

	Write(EnumOut, '	' + EnumName + ' = (');

	Child := Node.FirstChild;
	while Assigned(Child) do
	begin
		Write(EnumOut, TDOMElement(Child).GetAttribute('name'));

		Content := String(Child.TextContent);
		if Length(Content) > 0 then
		begin
			Write(EnumOut, ' := ' + IntegerTrans(Content));
		end;

		if Assigned(Child.NextSibling) then Write(EnumOut, ', ');

		Child := Child.NextSibling;
	end;

	WriteLn(EnumOut, ');');
end;

procedure ScanEnumerations();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('enumerations');

	WriteLn(EnumOut, 'type');

	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'enumeration' then ScanEnumeration(Child);
		Child := Child.NextSibling;
	end;
	List.Free();
end;

procedure ScanConstants();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('constants');

	WriteLn(ConstOut, 'const');

	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		WriteLn(ConstOut, '	' + String(TDOMElement(Child).GetAttribute('name')) + ' : Integer = ' + IntegerTrans(String(Child.TextContent)) + ';');
		Child := Child.NextSibling;
	end;
	List.Free();
end;

procedure ScanStruct(Node : TDOMNode);
var
	Child : TDOMNode;
	StructName : String;
begin
	StructName := String(TDOMElement(Node).GetAttribute('name'));

	WriteLn('Struct ' + StructName);

	WriteLn(StructOut, '	' + StructName + ' = packed record');

	Child := Node.FirstChild;
	while Assigned(Child) do
	begin
		WriteLn(StructOut, '		' + String(TDOMElement(Child).GetAttribute('name')) + ' : ' + TypeToPascal(Child) + ';');
		Child := Child.NextSibling;
	end;

	WriteLn(StructOut, '	end;');
	WriteLn(StructOut, '	P' + StructName + ' = ^' + StructName + ';');
end;

procedure ScanStructs();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('structs');

	WriteLn(StructOut, 'type');

	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'struct' then ScanStruct(Child);
		Child := Child.NextSibling;
	end;
	List.Free();
end;

function GetReturn(Node : TDOMNode) : TDOMNode;
var
	List : TDOMNodeList;
begin
	List := TDOMElement(Node).GetElementsByTagName('return');

	GetReturn := List[0].FirstChild;

	List.Free();
end;

function HasReturn(Node : TDOMNode) : Boolean;
var
	List : TDOMNodeList;
begin
	List := TDOMElement(Node).GetElementsByTagName('return');

	HasReturn := List.Count > 0;

	List.Free();
end;

function GetArgs(Node : TDOMNode) : TDOMNode;
var
	List : TDOMNodeList;
begin
	List := TDOMElement(Node).GetElementsByTagName('arguments');

	GetArgs := List[0];

	List.Free();
end;

function HasArgs(Node : TDOMNode) : Boolean;
var
	List : TDOMNodeList;
begin
	List := TDOMElement(Node).GetElementsByTagName('arguments');

	HasArgs := List.Count > 0;

	List.Free();
end;

procedure ScanFunction(Prefix : String; Node : TDOMNode);
var
	FuncName : String;
	Ret : TDOMNode;
	Child : TDOMNode;
	HasVa : Boolean;
begin
	FuncName := Prefix + String(TDOMElement(Node).GetAttribute('name'));

	WriteLn('Function ' + FuncName);

	if HasReturn(Node) then
	begin
		Write(FuncDefOut, 'function ');

		Ret := GetReturn(Node);
	end
	else Write(FuncDefOut, 'procedure ');

	Write(FuncDefOut, FuncName);

	HasVa := False;
	Write(FuncDefOut, '(');
	if Length(Prefix) > 0 then
	begin
		Write(FuncDefOut, 'handle : MwWidget');
		if HasArgs(Node) then
		begin
			Write(FuncDefOut, '; ');
		end;
	end;

	if HasArgs(Node) then
	begin
		Child := GetArgs(Node).FirstChild;
		while Assigned(Child) do
		begin
			if Child.NodeName = 'variable' then
			begin
				HasVa := True;
			end
			else
			begin
				Write(FuncDefOut, String(TDOMElement(Child).GetAttribute('name')) + ' : ' + TypeToPascal(Child));

				if (Assigned(Child.NextSibling)) and not(Child.NextSibling.NodeName = 'variable') then Write(FuncDefOut, '; ');
			end;

			Child := Child.NextSibling;
		end;
	end;
	Write(FuncDefOut, ')');

	if HasReturn(Node) then
	begin
		Write(FuncDefOut, ' : ' + TypeToPascal(Ret));
	end;

	if Length(Prefix) = 0 then
	begin
		Write(FuncDefOut, '; cdecl; ');
		if HasVa then Write(FuncDefOut, 'varargs; ');
		WriteLn(FuncDefOut, 'external name ''' + FuncName + ''';');
	end
	else
	begin
		WriteLn(FuncDefOut, ';');
	end;
end;

procedure ScanFunctions(Prefix : String; Node : TDOMNode);
var
	Child : TDOMNode;
begin
	Child := Node.FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'function' then ScanFunction(Prefix, Child);
		Child := Child.NextSibling;
	end;
end;

procedure ScanHeader(Node : TDOMNode);
var
	Child : TDOMNode;
begin
	WriteLn('Header ' + TDOMElement(Node).GetAttribute('name'));

	WriteLn(FuncDefOut, '(* Header ' + TDOMElement(Node).GetAttribute('name') + ' *)');

	Child := Node.FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'functions' then ScanFunctions('', Child);
		Child := Child.NextSibling;
	end;

	WriteLn(FuncDefOut, '');
end;

procedure ScanHeaders();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('headers');

	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'header' then ScanHeader(Child);
		Child := Child.NextSibling;
	end;
	List.Free();
end;

procedure ScanWidget(Node : TDOMNode);
var
	Child : TDOMNode;
begin
	WriteLn('Widget ' + TDOMElement(Node).GetAttribute('name'));

	WriteLn(FuncDefOut, '(* Widget ' + TDOMElement(Node).GetAttribute('name') + ' *)');

	Child := Node.FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'functions' then ScanFunctions('Mw' + String(TDOMElement(Node).GetAttribute('name')), Child);
		Child := Child.NextSibling;
	end;

	WriteLn(FuncDefOut, '');

	WriteLn(VarOut, '	Mw' + TDOMElement(Node).GetAttribute('name') + 'Class : Pointer; external name ''Mw' + TDOMElement(Node).GetAttribute('name') + 'Class'';');
end;

procedure ScanWidgets();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('widgets');

	WriteLn(VarOut, 'var');

	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		if Child.NodeName = 'widget' then ScanWidget(Child);
		Child := Child.NextSibling;
	end;
	List.Free();
end;

begin
	AssignFile(StructOut, 'src/structh.inc');
	AssignFile(PropOut, 'src/proph.inc');
	AssignFile(EnumOut, 'src/enumh.inc');
	AssignFile(ConstOut, 'src/consth.inc');
	AssignFile(FuncDefOut, 'src/funch.inc');
	AssignFile(VarOut, 'src/varh.inc');

	Rewrite(StructOut);
	Rewrite(PropOut);
	Rewrite(EnumOut);
	Rewrite(ConstOut);
	Rewrite(FuncDefOut);
	Rewrite(VarOut);

	Prop := TPropDict.Create();

	ReadXMLFile(XML, 'milsko/milsko.xml');
	ScanStructs();
	ScanProperties();
	ScanEnumerations();
	ScanConstants();
	ScanHeaders();
	ScanWidgets();

	XML.Free();

	CloseFile(VarOut);
	CloseFile(FuncDefOut);
	CloseFile(ConstOut);
	CloseFile(EnumOut);
	CloseFile(PropOut);
	CloseFile(StructOut);
end.
