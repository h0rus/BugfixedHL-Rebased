"Resource/HudLayout.res"
{
	"HudChat"
	{
		"ControlName"		"EditablePanel"
		"fieldName" 		"HudChat"
		"visible" 		"1"
		"enabled" 		"1"
		"xpos"			"10"
		"ypos"			"275"
		"wide"	 		"320"
		"tall"	 		"120"
		"PaintBackgroundType"	"2"
	}
	
	HudVoiceSelfStatus
	{
		"fieldName" "HudVoiceSelfStatus"
		"visible" "1"
		"enabled" "1"
		"xpos" "r43"
		"ypos" "355"
		"wide" "24"
		"tall" "24"
	}

	HudVoiceStatus
	{
		"fieldName" "HudVoiceStatus"
		"visible" "1"
		"enabled" "1"
		"xpos" "r145"
		"ypos" "0"
		"wide" "145"
		"tall" "400"

		"item_wide"	"135"
		
		"show_avatar"		"1"
		"show_friend"		"0"
		
		"show_dead_icon"	"1"
		"dead_xpos"			"1"
		"dead_ypos"			"0"
		"dead_wide"			"16"
		"dead_tall"			"16"
		
		"show_voice_icon"	"1"
		"icon_ypos"			"1"
		"icon_xpos"			"1"
		"icon_tall"			"15"
		"icon_wide"			"15"
		
		"text_xpos"			"33"
		
		"fade_in_time"		"0"
		"fade_out_time"		"0.15"
	}
	
	HudDeathNoticePanel
	{
		"fieldName"			"HudDeathNoticePanel"
		"visible"			"1"
		"enabled"			"1"
		"xpos"				"r640"
		"ypos"				"24"
		"wide"				"628"
		"tall"				"468"
		
		"hor_padding"		"12"		// Left and right padding of a row
		"icon_padding"		"2"			// Left and tight padding of the kill icon
		"vert_margin"		"4"			// Distance between rows
		"row_height"		"13"		// Height of a row
		"text_font"			"Default"
		
		// Background color
		"color_bg"			"KF_Background"
		"color_bg_kill"		"KF_Background_Kill"
		"color_bg_death"	"KF_Background_Death"
		
		// Icon color
		"color_icon"		"KF_Icon"
		"color_icon_kill"	"KF_Icon_Kill"
		"color_icon_death"	"KF_Icon_Death"
		"color_icon_teamkill"	"KF_Icon_Teamkiill"
		
		// Default name color
		"default_name_color"	"Orange"
	}
}
