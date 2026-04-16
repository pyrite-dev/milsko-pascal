type
	MwPoint = packed record
		x : Integer;
		y : Integer;
	end;
	PMwPoint = ^MwPoint;
	MwRect = packed record
		x : Integer;
		y : Integer;
		width : Integer;
		height : Integer;
	end;
	PMwRect = ^MwRect;
	MwSizeHints = packed record
		min_width : Integer;
		min_height : Integer;
		max_width : Integer;
		max_height : Integer;
	end;
	PMwSizeHints = ^MwSizeHints;
	MwRGB = packed record
		red : Word;
		green : Word;
		blue : Word;
	end;
	PMwRGB = ^MwRGB;
	MwMouse = packed record
		point : MwPoint;
		button : Integer;
	end;
	PMwMouse = ^MwMouse;
	MwVulkanConfig = packed record
		api_version : Cardinal;
		vk_version : Cardinal;
		validation_layers : Integer;
	end;
	PMwVulkanConfig = ^MwVulkanConfig;
