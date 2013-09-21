##Lava, the burning suite for Haiku OS
*License: MIT*    
*Authors: Jan64, Negr0, GenKi, SprMa, FinN, stargater*        

###The components
>**LibBurnDevice** - Doing the actual burning, a library accessing cdrecord etc.

>**Lava** - The Tracker add-on

>**BurnDevice** - The preference panel

###The basic idea
*GUI* <-------> *LibBurnDevice* <------> *cdrecord/libburn*  
LibBurnDevice is a class to easily access cdrecord and other tools. Any GUI application, Tracker add-on etc. only needs to know this one class and won't have to deal with the gory details of burning.

###The architecture

####Project management     
There's no real application for project management planned. Projects are stored in a folder in the filesystem (e.g. /boot/home/burn/) with subfolders representing the different projects (e.g. /boot/home/burn/project-1). These subfolders in turn contain for every added file an empty file with attributes holding information about the added file, see Jan's suggestion on Caspar-Wendy-Style. Unwanted files can simply be removed from the project folder.

If the Tracker add-on is invoked on a file, a dialog opens to decide to which project the file should be added or if a new project should be created for it. A new project automatically creates a folder in /boot/home/burn/.

####Add-on
The Tracker add-on is used to add files to a project. It's dialog shows a list of all files in the project and a button to start the burning. If you choose not to burn and just close the window, you can continue to add more files to this project.

####Burning
Besides using the button in the add-on after adding files to start the burning, you can also invoke the add-on on a project folder at a later time.

###Short introduction to LibBurnDevice
LibBurnDevice's goal is to keep the burning as simple as possible. Still, there are a few useful methods that need some explaining:

* The constructor **BurnDevice()** sets all burning option to default values, checks the version of cdrecord and gets information on all available burning devices. It doesn't set a device yet, however!
* For that, you invoke **GetBurnDevices()** which returns a BList with pointers to objects of the type **burn_device**.
* A **burn_device** holds strings with information to: *device number*, *manufacturer*, *device name*, *additional name*.
* With **SetBurnDevice()** you then set a device of this list as default device.


###Screenshots

####The Tracker add-on "Lava"  
#####Lava Project Window GUI v01M:
![Lava Project Window][1]
 
#####Lava Status&Burn Window GUI v01c:
![Lava Statusbar][2]


        
        
####The BurnDevice preferences
#####Preferences GUI v05:
![Preferences][3]


  [1]: http://dev.osdrawer.net/attachments/download/268
  [2]: http://dev.osdrawer.net/attachments/download/269
  [3]: http://dev.osdrawer.net/attachments/download/270





