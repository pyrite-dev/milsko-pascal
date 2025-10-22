(* Header Core *)
function MwCreateWidget(widget_class : MwClass; name : PChar; parent : MwWidget; x : Integer; y : Integer; width : Cardinal; height : Cardinal) : MwWidget; cdecl; external name 'MwCreateWidget';
function MwVaCreateWidget(widget_class : MwClass; name : PChar; parent : MwWidget; x : Integer; y : Integer; width : Cardinal; height : Cardinal) : MwWidget; cdecl; varargs; external name 'MwVaCreateWidget';
procedure MwVaWidgetExecute(handle : MwWidget; func_name : PChar; output : Pointer); cdecl; varargs; external name 'MwVaWidgetExecute';
procedure MwDestroyWidget(handle : MwWidget); cdecl; external name 'MwDestroyWidget';
procedure MwLoop(handle : MwWidget); cdecl; external name 'MwLoop';
procedure MwStep(handle : MwWidget); cdecl; external name 'MwStep';
function MwPending(handle : MwWidget) : Integer; cdecl; external name 'MwPending';
procedure MwSetInteger(handle : MwWidget; key : PChar; n : Integer); cdecl; external name 'MwSetInteger';
procedure MwSetText(handle : MwWidget; key : PChar; value : PChar); cdecl; external name 'MwSetText';
procedure MwSetVoid(handle : MwWidget; key : PChar; value : Pointer); cdecl; external name 'MwSetVoid';
function MwGetInteger(handle : MwWidget; key : PChar) : Integer; cdecl; external name 'MwGetInteger';
function MwGetText(handle : MwWidget; key : PChar) : PChar; cdecl; external name 'MwGetText';
function MwGetVoid(handle : MwWidget; key : PChar) : Pointer; cdecl; external name 'MwGetVoid';
procedure MwSetDefault(handle : MwWidget); cdecl; external name 'MwSetDefault';
procedure MwVaApply(handle : MwWidget); cdecl; varargs; external name 'MwVaApply';
procedure MwAddUserHandler(handle : MwWidget; key : PChar; handler : MwUserHandler; user_data : Pointer); cdecl; external name 'MwAddUserHandler';
procedure MwDispatchUserHandler(handle : MwWidget; key : PChar; handler_data : Pointer); cdecl; external name 'MwDispatchUserHandler';
procedure MwSetErrorHandler(handler : MwErrorHandler; user_data : Pointer); cdecl; external name 'MwSetErrorHandler';
procedure MwDispatchError(code : Integer; message : PChar); cdecl; external name 'MwDispatchError';
procedure MwForceRender(handle : MwWidget); cdecl; external name 'MwForceRender';
procedure MwForceRender2(handle : MwWidget; ptr : Pointer); cdecl; external name 'MwForceRender2';
procedure MwAddTickList(handle : MwWidget); cdecl; external name 'MwAddTickList';
procedure MwFocus(handle : MwWidget); cdecl; external name 'MwFocus';
procedure MwGrabPointer(handle : MwWidget; toggle : Integer); cdecl; external name 'MwGrabPointer';
procedure MwHideCursor(handle : MwWidget); cdecl; external name 'MwHideCursor';

(* Header Error *)
function MwGetLastError() : PChar; cdecl; external name 'MwGetLastError';

(* Header FileChooser *)
function MwFileChooser(handle : MwWidget; title : PChar) : MwWidget; cdecl; external name 'MwFileChooser';

(* Header MessageBox *)
function MwMessageBox(handle : MwWidget; text : PChar; title : PChar; flag : Cardinal) : MwWidget; cdecl; external name 'MwMessageBox';
function MwMessageBoxGetChild(handle : MwWidget; child : Integer) : MwWidget; cdecl; external name 'MwMessageBoxGetChild';
procedure MwMessageBoxDestroy(handle : MwWidget); cdecl; external name 'MwMessageBoxDestroy';

(* Header Widget/ListBox.h *)
function MwListBoxCreatePacket() : Pointer; cdecl; external name 'MwListBoxCreatePacket';
procedure MwListBoxDestroyPacket(packet : Pointer); cdecl; external name 'MwListBoxDestroyPacket';
function MwListBoxPacketInsert(packet : Pointer; index : Integer) : Integer; cdecl; external name 'MwListBoxPacketInsert';
procedure MwListBoxPacketSet(packet : Pointer; index : Integer; col : Integer; text : PChar); cdecl; external name 'MwListBoxPacketSet';
procedure MwListBoxPacketSetIcon(packet : Pointer; index : Integer; icon : MwLLPixmap); cdecl; external name 'MwListBoxPacketSetIcon';

(* Widget Button *)

(* Widget CheckBox *)

(* Widget Entry *)

(* Widget Frame *)

(* Widget Image *)

(* Widget Label *)

(* Widget ListBox *)
procedure MwListBoxInsert(handle : MwWidget; index : Integer; packet : Pointer);
procedure MwListBoxDelete(handle : MwWidget; index : Integer);
function MwListBoxGet(handle : MwWidget; index : Integer) : PChar;
procedure MwListBoxSetWidth(handle : MwWidget; index : Integer; width : Integer);
procedure MwListBoxReset(handle : MwWidget);

(* Widget Menu *)
function MwMenuAdd(handle : MwWidget; menu : Pointer; name : PChar) : Pointer;

(* Widget NumberEntry *)

(* Widget OpenGL *)
procedure MwOpenGLMakeCurrent(handle : MwWidget);
function MwOpenGLGetProcAddress(handle : MwWidget; name : PChar) : Pointer;
procedure MwOpenGLSwapBuffer(handle : MwWidget);

(* Widget ScrollBar *)
function MwScrollBarGetVisibleLength(handle : MwWidget) : Integer;

(* Widget SubMenu *)
procedure MwSubMenuAppear(handle : MwWidget; menu : Pointer; point : PMwPoint);

(* Widget Viewport *)
function MwViewportGetViewport(handle : MwWidget) : MwWidget;
procedure MwViewportSetSize(handle : MwWidget; w : Integer; h : Integer);

(* Widget Window *)
procedure MwWindowMakeBorderless(handle : MwWidget);

