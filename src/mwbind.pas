unit MwBind;

{$linklib Mw}

interface
type
	MwWidget = Pointer;
	PMwWidget = ^MwWidget;
	MwClass = Pointer;
	PMwClass = ^MwClass;
	MwUserHandler = procedure (handle : MwWidget; user_data : Pointer; client_data : Pointer); cdecl;
	MwErrorHandler = procedure (code : Integer; message : PChar; user_data : PChar); cdecl;

{$i structh.inc}
{$i proph.inc}
{$i enumh.inc}
{$i consth.inc}

{$i funch.inc}

implementation

end.
