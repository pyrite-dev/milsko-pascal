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
	EnumOut : TextFile;
	PropOut : TextFile;

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
	if (Node.NodeName = 'integer') and (TDOMElement(Node).GetAttribute('unsigned') = 'yes') then TypeToPascal := 'Cardinal';
	if (Node.NodeName = 'integer') and not(TDOMElement(Node).GetAttribute('unsigned') = 'yes') then TypeToPascal := 'Integer';
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

		WriteLn(PropOut, '	MwN' + TDOMElement(Child).GetAttribute('name') + ' : PChar = ''' + PropToString(TDOMElement(Child).GetAttribute('name')) + ''';');

		Child := Child.NextSibling;
	end;
	List.Free();
end;

function IntegerTrans(Content : String) : String;
begin
	IntegerTrans := Content;
	if (Length(Content) > 2) and (Copy(Content, 1, 2) = '0x') then
	begin
		IntegerTrans := '&' + Copy(Content, 3);
	end;
end;

procedure ScanEnumeration(Node : TDOMNode);
var
	Child : TDOMNode;
	Content : String;
begin
	WriteLn('Enumeration ' + TDOMElement(Node).GetAttribute('name'));

	Write(EnumOut, '	' + TDOMElement(Node).GetAttribute('name') + ' = (');

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

begin
	AssignFile(PropOut, 'src/proph.inc');
	AssignFile(EnumOut, 'src/enumh.inc');

	Rewrite(PropOut);
	Rewrite(EnumOut);

	Prop := TPropDict.Create();

	ReadXMLFile(XML, 'milsko/milsko.xml');
	ScanProperties();
	ScanEnumerations();

	XML.Free();

	CloseFile(EnumOut);
	CloseFile(PropOut);
end.
