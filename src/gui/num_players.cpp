//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "num_players.hpp"
#include "race_manager.hpp"
#include "widget_set.hpp"
#include "menu_manager.hpp"
#include "translation.hpp"

enum WidgetTokens {
    WTOK_PLAYER_2 = 2,
    WTOK_PLAYER_3,
    WTOK_PLAYER_4,
    WTOK_BACK
};

NumPlayers::NumPlayers()
{
    m_menu_id = widgetSet -> varray(0);
    widgetSet -> space(m_menu_id);
    widgetSet -> start(m_menu_id, _("Two Players"),   GUI_MED, WTOK_PLAYER_2);
    widgetSet -> state(m_menu_id, _("Three Players"), GUI_MED, WTOK_PLAYER_3);
    widgetSet -> state(m_menu_id, _("Four Players"),  GUI_MED, WTOK_PLAYER_4);
    widgetSet -> space(m_menu_id);
    widgetSet -> state(m_menu_id,_("Press <ESC> to go back"), GUI_SML, WTOK_BACK);
    widgetSet -> space(m_menu_id);

    widgetSet -> layout(m_menu_id, 0, 0);
}

// -----------------------------------------------------------------------------
NumPlayers::~NumPlayers()
{
    widgetSet -> delete_widget(m_menu_id) ;
}

// -----------------------------------------------------------------------------
void NumPlayers::select()
{
    const int CLICKED_ID = widgetSet -> get_token (widgetSet -> click());
    switch (CLICKED_ID)
    {
    case WTOK_PLAYER_2:
    case WTOK_PLAYER_3:
    case WTOK_PLAYER_4:
        race_manager->setNumPlayers(CLICKED_ID);
        menu_manager->pushMenu(MENUID_GAMEMODE);
        break;
    case WTOK_BACK:
        menu_manager->popMenu();
        break;
    default:
        break;
    }
}



