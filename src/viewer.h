/*
    Copyright (C) 2009 Andrew Caudwell (acaudwell@gmail.com)

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MANDELBULB_VIEWER_H
#define MANDELBULB_VIEWER_H

#include <time.h>

#include "core/sdlapp.h"
#include "core/display.h"
#include "core/shader.h"
#include "core/fxfont.h"
#include "core/conffile.h"
#include "core/pi.h"

#include "vcamera.h"
#include "ppm.h"

#define MANDELBULB_VIEWER_VERSION "0.1"

void mandelbulb_help();

class MandelbulbViewer : public SDLApp {

    int vwidth;
    int vheight;

    Shader* shader;
    FXFont font;

    ConfFile conf;

    bool debug;

    std::string shaderfile;

    std::string message;
    float message_timer;
    vec3f message_colour;


    float time_elapsed;

    bool play;
    bool record;
    int record_frame_skip;
    float record_frame_delta;
    FrameExporter* frameExporter;

    float runtime;
    float timescale;
    float fixed_tick_rate;

    int frame_skip;
    int frame_count;

    bool record_frame;

    ViewCameraPath campath;

    bool paused;
    bool animated;

    vec2f mousepos;
    bool roll;
    bool mouselook;

    ViewCamera view;
    Object3D mandelbulb;

    mat3f viewRotation;
    mat3f objRotation;

    bool constantSpeed;

    bool backgroundGradient;
    bool juliaset;
    vec3f julia_c;
    vec3f _julia_c;

    float speed;
    float fov;
    float cameraZoom;

    int antialiasing;
    bool phong;

    float shadows;

    float specularity;
    float specularExponent;

    float ambientOcclusion;
    float ambientOcclusionEmphasis;

    float power;
    float bounding;
    float bailout;
    float epsilonScale;
    int maxIterations;
    int stepLimit;

    float fogDistance;
    float aoSteps;

    float glowDepth;
    float glowMulti;
    vec3f glowColour;

    float beat;
    float beatTimer;
    float beatGlowDepth;
    float beatGlowMulti;
    int beatCount;
    int beatPeriod;

    bool radiolaria;
    float radiolariaFactor;

    float colorSpread;
    float rimLight;

    vec3f light;

    vec4f  backgroundColor;
    vec4f  diffuseColor;
    vec4f  ambientColor;
    vec4f  lightColor;

    void randomizeJuliaSeed();
    void randomizeColours();

    void togglePlay();
    void toggleRecord();

    void addWaypoint(float duration);

    void moveCam(float dt);

    void setMessage(const std::string& message, const vec3f& colour = vec3f(1.0, 1.0, 1.0));
    void setDefaults();

    GLuint rendertex;

    void drawAlignedQuad(int w, int h);

    void drawMandelbulb();
public:
    MandelbulbViewer(std::string conffile, float viewscale, float timescale);
    ~MandelbulbViewer();

    void logic(float t, float dt);
    void draw(float t, float dt);

    void createVideo(std::string filename, int video_framerate);

    bool readConfig();
    void saveConfig(bool saverec);

    //inherited methods
    void init();
    void update(float t, float dt);
    void keyPress(SDL_KeyboardEvent *e);
    void mouseMove(SDL_MouseMotionEvent *e);
    void mouseClick(SDL_MouseButtonEvent *e);
};

#endif
