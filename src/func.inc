(* Widget Box *)

(* Widget Button *)

(* Widget CheckBox *)

(* Widget Entry *)

(* Widget Frame *)

(* Widget Image *)

(* Widget Label *)
procedure MwLabelSetSevenSegment(handle : MwWidget; index : Integer; data : Integer);
begin
	MwVaWidgetExecute(handle, 'mwLabelSetSevenSegment', Nil, index, data);
end;


(* Widget ListBox *)
procedure MwListBoxInsert(handle : MwWidget; index : Integer; packet : Pointer);
begin
	MwVaWidgetExecute(handle, 'mwListBoxInsert', Nil, index, packet);
end;

procedure MwListBoxDelete(handle : MwWidget; index : Integer);
begin
	MwVaWidgetExecute(handle, 'mwListBoxDelete', Nil, index);
end;

function MwListBoxGet(handle : MwWidget; index : Integer) : PChar;
var
	RetVal : PChar;
begin
	MwVaWidgetExecute(handle, 'mwListBoxGet', Pointer(@RetVal), index);
MwListBoxGet := RetVal;
end;

procedure MwListBoxSetWidth(handle : MwWidget; index : Integer; width : Integer);
begin
	MwVaWidgetExecute(handle, 'mwListBoxSetWidth', Nil, index, width);
end;

procedure MwListBoxReset(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwListBoxReset', Nil);
end;


(* Widget Menu *)
function MwMenuAdd(handle : MwWidget; menu : Pointer; name : PChar) : Pointer;
var
	RetVal : Pointer;
begin
	MwVaWidgetExecute(handle, 'mwMenuAdd', Pointer(@RetVal), menu, name);
MwMenuAdd := RetVal;
end;


(* Widget NumberEntry *)

(* Widget OpenGL *)
procedure MwOpenGLMakeCurrent(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwOpenGLMakeCurrent', Nil);
end;

function MwOpenGLGetProcAddress(handle : MwWidget; name : PChar) : Pointer;
var
	RetVal : Pointer;
begin
	MwVaWidgetExecute(handle, 'mwOpenGLGetProcAddress', Pointer(@RetVal), name);
MwOpenGLGetProcAddress := RetVal;
end;

procedure MwOpenGLSwapBuffer(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwOpenGLSwapBuffer', Nil);
end;


(* Widget ScrollBar *)
function MwScrollBarGetVisibleLength(handle : MwWidget) : Integer;
var
	RetVal : Integer;
begin
	MwVaWidgetExecute(handle, 'mwScrollBarGetVisibleLength', Pointer(@RetVal));
MwScrollBarGetVisibleLength := RetVal;
end;


(* Widget SubMenu *)
procedure MwSubMenuAppear(handle : MwWidget; menu : Pointer; point : PMwPoint);
begin
	MwVaWidgetExecute(handle, 'mwSubMenuAppear', Nil, menu, point);
end;


(* Widget Viewport *)
function MwViewportGetViewport(handle : MwWidget) : MwWidget;
var
	RetVal : MwWidget;
begin
	MwVaWidgetExecute(handle, 'mwViewportGetViewport', Pointer(@RetVal));
MwViewportGetViewport := RetVal;
end;

procedure MwViewportSetSize(handle : MwWidget; w : Integer; h : Integer);
begin
	MwVaWidgetExecute(handle, 'mwViewportSetSize', Nil, w, h);
end;


(* Widget Window *)
procedure MwWindowMakeBorderless(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwWindowMakeBorderless', Nil);
end;


(* Widget ProgressBar *)

(* Widget RadioBox *)

(* Widget ComboBox *)
procedure MwComboBoxAdd(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwComboBoxAdd', Nil);
end;


(* Widget TreeView *)
procedure MwTreeViewAdd(handle : MwWidget; parent : Pointer; pixmap : MwLLPixmap; item : PChar);
begin
	MwVaWidgetExecute(handle, 'mwTreeViewAdd', Nil, parent, pixmap, item);
end;

procedure MwTreeViewDelete(handle : MwWidget; item : Pointer);
begin
	MwVaWidgetExecute(handle, 'mwTreeViewDelete', Nil, item);
end;

procedure MwTreeViewReset(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwTreeViewReset', Nil);
end;


(* Widget OpenGL *)
procedure MwOpenGLMakeCurrent(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwOpenGLMakeCurrent', Nil);
end;

function MwOpenGLGetProcAddress(handle : MwWidget; name : PChar) : Pointer;
var
	RetVal : Pointer;
begin
	MwVaWidgetExecute(handle, 'mwOpenGLGetProcAddress', Pointer(@RetVal), name);
MwOpenGLGetProcAddress := RetVal;
end;

procedure MwOpenGLSwapBuffer(handle : MwWidget);
begin
	MwVaWidgetExecute(handle, 'mwOpenGLSwapBuffer', Nil);
end;


(* Widget Vulkan *)
function MwVulkanGetField(handle : MwWidget; field : Integer; out : PInteger) : Pointer;
var
	RetVal : Pointer;
begin
	MwVaWidgetExecute(handle, 'mwVulkanGetField', Pointer(@RetVal), field, out);
MwVulkanGetField := RetVal;
end;


