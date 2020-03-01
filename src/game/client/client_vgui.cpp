#include <tier0/dbg.h>
#include <tier1/interface.h>
#include <tier1/tier1.h>
#include <tier2/tier2.h>
#include <IEngineVGui.h>
#include <vgui_controls/Controls.h>
#include <vgui/IPanel.h>
#include <convar.h>
#include "console.h"
#include "client_vgui.h"
#include "vgui/client_viewport.h"

EXPOSE_SINGLE_INTERFACE(CClientVGUI, IClientVGUI, ICLIENTVGUI_NAME);

void CClientVGUI::Initialize(CreateInterfaceFn *pFactories, int iNumFactories)
{
	ConnectTier1Libraries(pFactories, iNumFactories);
	ConnectTier2Libraries(pFactories, iNumFactories);

	if (!vgui2::VGui_InitInterfacesList("CLIENT", pFactories, iNumFactories))
	{
		Error("Failed to intialize VGUI2\n");
		Assert(false);
	}

	new CClientViewport();
}

void CClientVGUI::Start()
{
}

void CClientVGUI::SetParent(vgui2::VPANEL parent)
{
}

int CClientVGUI::UseVGUI1()
{
	return false;
}

void CClientVGUI::HideScoreBoard()
{
}

void CClientVGUI::HideAllVGUIMenu()
{
}

void CClientVGUI::ActivateClientUI()
{
	g_pViewport->ActivateClientUI();
}

void CClientVGUI::HideClientUI()
{
	g_pViewport->HideClientUI();
}

void CClientVGUI::Shutdown()
{
	// Warning! Only called for CS & CZ
	// Do not use!
}

static void DumpPanel(vgui2::VPANEL panel, int offset, bool bParentVisible)
{
	char buf[256];
	memset(buf, ' ', sizeof(buf));
	if (offset * 10 >= sizeof(buf))
		offset = sizeof(buf) - 1;
	buf[offset] = '\0';

	int wide, tall;
	g_pVGuiPanel->GetSize(panel, wide, tall);

	bool bIsVisible = g_pVGuiPanel->IsVisible(panel) && bParentVisible;
	Color color = console::GetColor();
	if (bParentVisible)
	{
		if (bIsVisible)
			color = ConColor::Green;
		else
			color = ConColor::Red;
	}

	ConPrintf(color, "%s%s [%s %d x %d]\n", buf,
	    g_pVGuiPanel->GetName(panel),
	    g_pVGuiPanel->GetClassName(panel),
	    wide, tall);

	int count = g_pVGuiPanel->GetChildCount(panel);
	for (int i = 0; i < count; i++)
	{
		DumpPanel(g_pVGuiPanel->GetChild(panel, i), offset + 1, bIsVisible);
	}
}

CON_COMMAND(vgui_dumptree, "Dumps VGUI2 panel tree for debugging.")
{
	ConPrintf("Green - visible\nRed - hidden\n\n");
	DumpPanel(g_pEngineVGui->GetPanel(PANEL_ROOT), 0, true);
}