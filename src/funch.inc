(* Header Dialog/ColorPicker *)
function MwColorPicker(handle : MwWidget; title : PChar) : MwWidget; cdecl; external name 'MwColorPicker';

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
procedure MwSetDarkTheme(handle : MwWidget; toggle : Integer); cdecl; external name 'MwSetDarkTheme';
function MwGetParent(handle : MwWidget) : MwWidget; cdecl; external name 'MwGetParent';
procedure MwLibraryInit(); cdecl; external name 'MwLibraryInit';
procedure MwShow(handle : MwWidget; toggle : Integer); cdecl; external name 'MwShow';
function MwGetName(handle : MwWidget) : PChar; cdecl; external name 'MwGetName';
function MwGetChildren(handle : MwWidget) : PMwWidget; cdecl; external name 'MwGetChildren';
procedure MwGetCursorCoord(handle : MwWidget; point : PMwPoint); cdecl; external name 'MwGetCursorCoord';
procedure MwGetScreenSize(handle : MwWidget; rect : PMwRect); cdecl; external name 'MwGetScreenSize';
procedure MwGetClipboard(handle : MwWidget; clipboard_type : Integer); cdecl; external name 'MwGetClipboard';
function MwGetClass(handle : MwWidget) : MwClass; cdecl; external name 'MwGetClass';
procedure MwSetUser(handle : MwWidget; user : Pointer); cdecl; external name 'MwSetUser';
function MwGetUser(handle : MwWidget) : Pointer; cdecl; external name 'MwGetUser';
procedure MwFreeWidget(handle : MwWidget); cdecl; external name 'MwFreeWidget';

(* Header Dialog/FileChooser *)
function MwFileChooser(handle : MwWidget; title : PChar) : MwWidget; cdecl; external name 'MwFileChooser';
function MwFileChooserEx(handle : MwWidget; title : PChar; dir : Integer) : MwWidget; cdecl; external name 'MwFileChooserEx';

(* Header Dialog/DirectoryChooser *)
function MwDirectoryChooser(handle : MwWidget; title : PChar) : MwWidget; cdecl; external name 'MwDirectoryChooser';

(* Header Dialog/MessageBox *)
function MwMessageBox(handle : MwWidget; text : PChar; title : PChar; flag : Cardinal) : MwWidget; cdecl; external name 'MwMessageBox';
function MwMessageBoxGetChild(handle : MwWidget; child : Integer) : MwWidget; cdecl; external name 'MwMessageBoxGetChild';

(* Widget Box *)

(* Widget Button *)

(* Widget Calendar *)

(* Widget CheckBox *)

(* Widget Entry *)

(* Widget Frame *)

(* Widget Image *)

(* Widget Label *)
procedure MwLabelSetSevenSegment(handle : MwWidget; index : Integer; data : Integer);

(* Widget ListBox *)
function MwListBoxSet(handle : MwWidget; row : Integer; col : Integer; text : PChar) : Integer;
procedure MwListBoxSetIcon(handle : MwWidget; index : Integer; icon : MwLLPixmap);
procedure MwListBoxDelete(handle : MwWidget; index : Integer);
function MwListBoxGet(handle : MwWidget; index : Integer) : PChar;
procedure MwListBoxSetWidth(handle : MwWidget; index : Integer; width : Integer);
procedure MwListBoxReset(handle : MwWidget);

(* Widget Menu *)
function MwMenuAdd(handle : MwWidget; menu : Pointer; name : PChar) : Pointer;

(* Widget NumberEntry *)

(* Widget ScrollBar *)
function MwScrollBarGetVisibleLength(handle : MwWidget) : Integer;

(* Widget SubMenu *)
procedure MwSubMenuAppear(handle : MwWidget; menu : Pointer; point : PMwPoint; diff_calc : Integer);
procedure MwSubMenuGetSize(handle : MwWidget; menu : Pointer; rect : PMwRect);

(* Widget Viewport *)
function MwViewportGetViewport(handle : MwWidget) : MwWidget;
procedure MwViewportSetSize(handle : MwWidget; w : Integer; h : Integer);

(* Widget Window *)
procedure MwWindowMakeBorderless(handle : MwWidget);

(* Widget ProgressBar *)

(* Widget RadioBox *)

(* Widget ComboBox *)
procedure MwComboBoxAdd(handle : MwWidget);

(* Widget TreeView *)
procedure MwTreeViewAdd(handle : MwWidget; parent : Pointer; pixmap : MwLLPixmap; item : PChar);
procedure MwTreeViewDelete(handle : MwWidget; item : Pointer);
procedure MwTreeViewSetOpened(handle : MwWidget; item : Pointer; opened : Integer);
function MwTreeViewGetOpened(handle : MwWidget; item : Pointer) : Integer;
procedure MwTreeViewReset(handle : MwWidget);

(* Widget SubWindow *)
function MwSubWindowGetFrame(handle : MwWidget) : MwWidget;

(* Widget Table *)

(* Widget Tab *)
function MwTabAdd(handle : MwWidget; name : PChar) : MwWidget;
function MwTabGetFrame(handle : MwWidget; name : PChar) : MwWidget;

(* Widget OpenGL *)
procedure MwOpenGLMakeCurrent(handle : MwWidget);
function MwOpenGLGetProcAddress(handle : MwWidget; name : PChar) : Pointer;
procedure MwOpenGLSwapBuffer(handle : MwWidget);

(* Widget Vulkan *)
function MwVulkanGetField(handle : MwWidget; field : Integer; output : PInteger) : Pointer;

