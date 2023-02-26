// This file is a part of  DaVinci
// Copyright (C) 2022  akshay bansod <aksh.bansod@yahoo.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef IMGUI_RENDERER_HPP
#define IMGUI_RENDERER_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define DEFAULT_FRAME_DELAY 1000 / 60

class imguiRenderer
{
public:    
    imguiRenderer(GLFWwindow* win,  void (*func)());

    void render();

    void beginRendering();
    void stopRendering();

    bool isRenderingActive() { return shouldRender;}

    void setFps(int fps=30);

private:
    std::chrono::milliseconds frameDelay = std::chrono::milliseconds(DEFAULT_FRAME_DELAY);
    std::thread* renderThread=0;
    bool shouldRender = true;
private:

    void static stat_render(imguiRenderer* rend);

    void (*script)();
    GLFWwindow* window;
};

#endif  //IMGUI_RENDERER_HPP
