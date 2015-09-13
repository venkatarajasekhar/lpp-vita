/*----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#------  This File is Part Of : ----------------------------------------------------------------------------------------#
#------- _  -------------------  ______   _   --------------------------------------------------------------------------#
#------ | | ------------------- (_____ \ | |  --------------------------------------------------------------------------#
#------ | | ---  _   _   ____    _____) )| |  ____  _   _   ____   ____   ----------------------------------------------#
#------ | | --- | | | | / _  |  |  ____/ | | / _  || | | | / _  ) / ___)  ----------------------------------------------#
#------ | |_____| |_| |( ( | |  | |      | |( ( | || |_| |( (/ / | |  --------------------------------------------------#
#------ |_______)\____| \_||_|  |_|      |_| \_||_| \__  | \____)|_|  --------------------------------------------------#
#------------------------------------------------- (____/  -------------------------------------------------------------#
#------------------------   ______   _   -------------------------------------------------------------------------------#
#------------------------  (_____ \ | |  -------------------------------------------------------------------------------#
#------------------------   _____) )| | _   _   ___   ------------------------------------------------------------------#
#------------------------  |  ____/ | || | | | /___)  ------------------------------------------------------------------#
#------------------------  | |      | || |_| ||___ |  ------------------------------------------------------------------#
#------------------------  |_|      |_| \____|(___/   ------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Licensed under the GPL License --------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Copyright (c) Nanni <lpp.nanni@gmail.com> ---------------------------------------------------------------------------#
#- Copyright (c) Rinnegatamante <rinnegatamante@gmail.com> -------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Credits : -----------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Smealum for ctrulib and ftpony src ----------------------------------------------------------------------------------#
#- StapleButter for debug font -----------------------------------------------------------------------------------------#
#- Lode Vandevenne for lodepng -----------------------------------------------------------------------------------------#
#- Jean-loup Gailly and Mark Adler for zlib ----------------------------------------------------------------------------#
#- Special thanks to Aurelio for testing, bug-fixing and various help with codes and implementations -------------------#
#-----------------------------------------------------------------------------------------------------------------------*/

#ifndef __LUAPLAYER_H
#define __LUAPLAYER_H

#include <stdlib.h>
//#include <tdefs.h> //Not needed for compilation via Ubuntu (complains it's missing)
#include "lua/lua.hpp"
#include <vector>

extern void luaC_collectgarbage (lua_State *L);

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(val, min, max) ((val)>(max)?(max):((val)<(min)?(min):(val)))

const char *runScript(const char* script, bool isStringBuffer);
void luaC_collectgarbage (lua_State *L);

void luaControls_init(lua_State *L);
void luaScreen_init(lua_State *L);
void luaSystem_init(lua_State *L);
void luaNetwork_init(lua_State *L);
void luaTimer_init(lua_State *L);

//Register our Color Functions
static const luaL_Reg Color_functions[] = {
  {"new",                				lua_color},
  {"getR",								lua_getR},
  {"getG",								lua_getG},
  {"getB",								lua_getB},
  {"getA",								lua_getA},
  {0, 0}
};
vector <static const luaL_Reg> v_LuaRegColourFunctions(Color_functions);
//Register our Screen Functions
static const luaL_Reg Screen_functions[] = {
  {"initBlend",							lua_init},
  {"termBlend",							lua_term},
  {"debugPrint",						lua_print},
  {"drawPixel",							lua_pixel},
  {"drawLine",							lua_line},
  {"fillRect",							lua_rect},
  {"fillCircle",						lua_circle},
  {"clear",								lua_clear},
  {"flip",								lua_flip},
  {"loadImage",							lua_loadimg},
  {"drawImage",							lua_drawimg},
  {"drawRotateImage",					lua_drawimg_rotate},
  {"drawScaleImage",					lua_drawimg_scale},
  {"drawPartialImage",					lua_drawimg_part},
  {"drawImageExtended",					lua_drawimg_full},
  {"createImage",						lua_createimage},
  {"getImageWidth",						lua_width},
  {"getImageHeight",					lua_height},
  {"getFramerate",						lua_getFPS},
  {"freeImage",							lua_free},
  {0, 0}
};
vector <static const luaL_Reg> v_LuaRegScreenFunctions(Screen_functions);

//Register our Font Functions
static const luaL_Reg Font_functions[] = {
  {"load",					lua_loadFont}, 
  {"print",					lua_fprint}, 
  {"setPixelSizes",			lua_fsize}, 
  {"unload",				lua_unloadFont}, 
  {0, 0}
};

vector <static const luaL_Reg> v_LuaRegFontFunctions(Font_functions);

extern int clr_color;
extern char cur_dir[256];

typedef struct {
	uint32_t magic;
	vita2d_font* f;
	int size;
}ttf;
namespace LuaLppVita{
class LuaScreen{
  public:
  static int lua_print(lua_State*);
  static int lua_pixel(lua_State*);
  static int lua_rect(lua_State *);
  
  };
}

#endif
