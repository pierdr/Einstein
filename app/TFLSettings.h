// ==============================
// File:			TFLSettings
// Project:			Einstein
//
// Copyright 2003-2007 by Paul Guyot (pguyot@kallisys.net).
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
// ==============================
// $Id$
// ==============================

// generated by Fast Light User Interface Designer (fluid) version 1.0400

#ifndef T_FL_SETTINGS_H
#define T_FL_SETTINGS_H


class Fl_Double_Window;
class TFLApp;


class TFLSettings
{
public:
    TFLSettings();
    virtual ~TFLSettings();
    virtual Fl_Double_Window *CreateSettingsPanel() = 0;
    virtual Fl_Double_Window *createAboutDialog() = 0;
    virtual void revertDialog() = 0;
    virtual void runningMode() = 0;
    virtual void HandlePopupMenu() = 0;

    void ShowAboutDialog();
    void ShowSettingsPanelModal();
    void ShowSettingsPanel();
    void setApp(TFLApp *App, const char *AppPath);
    void loadPreferences();
    void savePreferences();

    void SetMachineID(int inMachine);

//protected:
    Fl_Double_Window *mSettingsPanel = nullptr;
    Fl_Double_Window *mAboutDialog = nullptr;
    TFLApp *app = nullptr;
    char *appPath = nullptr;
    char *ROMPath = nullptr;
    char *FlashPath = nullptr;
    char *MachineID = nullptr;
    int machine;
    int screenWidth;
    int screenHeight;
    int hideMouse;
    int useMonitor;
    int fullScreen;
    int RAMSize;
    int dontShow;

};

#endif // T_FL_SETTINGS_H
