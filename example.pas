program test;

uses
	MwBind;

var
	Main, Listbox : MwWidget;
	Packet : Pointer;
	Index : Integer;
begin
	Main := MwCreateWidget(MwWindowClass, 'main', Nil, MwDEFAULT, MwDEFAULT, 640, 480);
	Listbox := MwCreateWidget(MwListBoxClass, 'listbox', main, 5, 5, 630, 470);

	Packet := MwListBoxCreatePacket();
	Index := MwListBoxPacketInsert(Packet, -1);
	MwListBoxPacketSet(Packet, Index, 0, 'Hello, world!');
	Index := MwListBoxPacketInsert(Packet, -1);
	MwListBoxPacketSet(Packet, Index, 0, 'lorem ipsum');
	MwListBoxInsert(Listbox, -1, Packet);
	MwListBoxDestroyPacket(Packet);

	MwLoop(Main);
end.
