type
	MwPoint = packed record
		x : Integer;
		y : Integer;
	end;
	PMwPoint = ^MwPoint;
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
