# UnrealEngine4-EZ-Mobile-Ads
One line code(or blueprint) Integrates Google AdMod and other ad networks for iOS &amp; Android.

EZ Mobile Ads help you easy integrates multiple ad networks for your game both Android and IOS same code, 
By use multiple ad networks, it will  help you maximize fill rate and increase monetization.
All features are available in C++ and Blueprint. this plugin automatic process ads reload and other detail, so
 you can easy use just call when you need.
 
Note: if you use multiple ad networks(for example 3 or 4 ad networks) in one project, you can use [this plugin](https://github.com/feixuwu/UnrealEngine4-Admob) to better manager and maximize monetization, it support more ad networks, and you can manage your ad networks dynamic(add or remove) by admob mediation system on the webpage. when you add a new ad network, you don't need to rebuild your client, it's a better choice.

# FEATURES: 
★ 4 best game ad networks supported (more coming soon).

★  all ad  networks  can enable and disable in editor setting.

★  extremely easy  integrates just one line c++ code or blueprint for both IOS and Android. plugin automatic process ads reload
  and other detail.

★  supoort unreal engine 4 4.15,4.16 and 4.17.

★ support via e-mail feixuwu@outlook.com


# PLATFORM SUPPORTED:
★ Android

★ IOS

# AD TYPES:
★ Banner

★ Interstitial (text, picture, video)

★ Reward Video

# SUPPORTED AD NETWORKS(more comming soon): 
★ AdMob

★ Vungle

★ ChartBoost

★ Unity

# Install

Watch this video to learn how to use the plugin

[![how to use this plugin](https://img.youtube.com/vi/DRtkq0ewTz4/0.jpg)](https://youtu.be/DRtkq0ewTz4)

1、Please first confirm you installed Visual Studio 2015 or 2017, and installed c++ compile support.

2、If your project is a pure blueprint project, please add an empty c++ class to the project, or else the plugin may not be compiled.

3、Copy Plugins folder to your project root folder, double click to open your game project as usual, the engine will 
 notify you to compile the plugin, confirm to compile the plugin, wait several minutes(3-5), the editor will lauched. If there is  any problem(UBT is complicate, and some bugs), please contact me let me help you to fix it.


# Usage
  you can simply run the demo project for test, to integrates your own project, juse few steps:
  
1、Copy Plugins folder to your project and compile the editor.

2、Want Unity Ads? easy!!
      open project editor and find Unity Setting,  fill your application id for both Android and IOS.
      ![ScreenShot](docs/config.PNG)
      
3、In blueprint Editor, when you want show show the ads, just call function "PlayRewardedVideo",  setting the ad platform Unity . 
       you can add custom event to process after user complete watched the ads video.
	![ScreenShot](docs/call.PNG)
	
4、Important:Remember that admob rewarded video  does not have fill rate on adnroid in most region, this is not a bug, so I suggest people switch to this plugin
 advance version: https://github.com/feixuwu/UnrealEngine4-Admob, try both have same API, it support admob mediation, 
 so you can add thirdparty ad network dynamic on the google admob webpage.
 

	  
# Other ShowCase
★ Want show Banner?
	![ScreenShot](docs/banner.PNG)

★ Want show interstitial?
	![ScreenShot](docs/interstitial.PNG)
	 
★ Want reward player with confiure coins from chartBoost?  
	![ScreenShot](docs/chartboost.PNG)
	
	
★ Want maximize fill rate and increase monetization?
	![ScreenShot](docs/max.PNG)
	
	
# Support
  
  Email:feixuwu@outlook.com
  Remote Assistance with teamviewer
  
# License
 You can use this plugin for free during trial purpose. If it earns less than $1000 for you, you can continue to use for free.

If you have monetized more than $1000 using this plugin, you are also required to: either get a commercial license ($20), or, no need pay but share 2% Ad traffic, read the [License Agreement](docs/License-Agreement.md) for details. As a commercial customer, you will be supported with high priority.

# FAQ

## ★ I'm not good with C++, can I use this plugin?

  Yes, of course you can, use this plugin, you don't have to have C++ knowlege, and don't need recompile the all engine. 
  
  But you need to have visualstudio or xcode can build C++ code, just put the plugins folder under you project root folder,  
  then double click the uproject file as usual, after several minutes(3-5), the editor will launch.
  
## ★ If I use in project with engine version 4.17, it will remind me the plugin is not compatible with engine, is there compatible problem?

 No, after do some debug and read 4.17 source, I found it's the engine bug, all the plugin without binary will get the warning.
 There's a engine bug report here: https://issues.unrealengine.com/issue/UE-49007
 
 So after the engine remind you if disable the plugin, click no, and then confirm to build the plugin, next time to start the project,
 the warning will dissappear.
