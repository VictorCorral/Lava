/*
 * Copyright 2010 stargater <ralf.schuelke@googlemail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef LavaBurnDeviceWindow_H
#define LavaBurnDeviceWindow_H


#include <iostream> 
#include <Alert.h>
#include <Application.h>
#include <Button.h>
#include <List.h>
#include <ListItem.h>
#include <ListView.h>
#include <StringView.h>
#include <Window.h>

#include "include/BurnDevice.h"

const uint32 CHECKBUTTON = 'TBcb'; 
const uint32 DEVICELIST = 'TBdl'; 


// the window that receives messages
class LavaBurnDeviceWindow: public BWindow {
	public:
		LavaBurnDeviceWindow(BRect r, const char* name, window_type w, BMessage *msg);
		virtual void MessageReceived(BMessage *msg);
		virtual bool QuitRequested();
		/*{
			be_app_messenger.SendMessage(B_QUIT_REQUESTED); 
			return true;
		}*/
	
		~LavaBurnDeviceWindow();
	
		BurnDevice *burner;
		BList *devList;
		BStringView *information;
	private:
	
};

#endif
