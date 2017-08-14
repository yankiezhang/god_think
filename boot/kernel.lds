SECTIONS
{
	.text : 
	{ 
		*(.text)
		. = 510;
		*(.label)
	}
}
