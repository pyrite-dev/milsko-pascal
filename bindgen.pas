program bindgen;

uses
	DOM,
	XMLRead,
	FGL;

type
	TPropDict = specialize TFPGMap<String, TDOMElement>;

var
	XML : TXMLDocument;
	Prop : TPropDict;

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

procedure ScanProperties();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('properties');
	
	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		Prop[String(TDOMElement(Child).GetAttribute('name'))] := TDOMElement(Child);
		Child := Child.NextSibling;
	end;
	List.Free();
end;

procedure ScanEnumerations();
var
	Child : TDOMNode;
	List : TDOMNodeList;
begin
	List := XML.DocumentElement.GetElementsByTagName('enumerations');
	
	Child := List[0].FirstChild;
	while Assigned(Child) do
	begin
		Child := Child.NextSibling;
	end;
	List.Free();
end;

begin
	Prop := TPropDict.Create();

	ReadXMLFile(XML, 'milsko/milsko.xml');
	ScanProperties();
	ScanEnumerations();

	XML.Free();
end.
