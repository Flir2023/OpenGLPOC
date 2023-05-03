#include <GLFW/glfw3.h>
#include "video_reader.hpp"
#include <iostream>
#include <cstdlib>
#define posix_memalign(p, a, s)  (((*(p)) = _aligned_malloc((s), (a))), *(p) ?0 :errno)
#include <stdio.h>
#include <fstream>
#include <vector>

int main(void)
{

    const int frame_width = 1920;
    const int frame_height = 1080;

    std::ifstream file("c:/users/am2/Desktop/testUncopresedRGB2", std::ios::in | std::ios::out | std::ios::binary |
        std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    if (file.read(buffer.data(), size))
    {
        std::cout << "File read and size is: " << size << std::endl;
    }

    int sz = (int)size;
    uint8_t* buf = (uint8_t*)buffer.data();
    
    //std::vector<uint8_t> yVec, uVec, vVec;
    //std::vector<uint8_t> new_buf;

    //for (int i = 0; i < sz * 2 / 3; ++i)
    //    yVec.push_back(*(buf + i));

    //for (int i = sz * 2 / 3; i < sz * 5 / 6; ++i)
    //    uVec.push_back(*(buf + i));

    //for (int i = sz * 5 / 6; i < sz; ++i)
    //    vVec.push_back(*(buf + i));

    ////for (int i = sz * 2 / 3; i < sz * 5 / 6; ++i) {
    ////    uVec[i - sz * 2 / 3] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + 1] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + frame_width] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + frame_width + 1] = *(buf + i);
    ////}

    ////for (int i = sz * 5 / 6; i < sz; ++i) {
    ////    vVec[i - sz * 5 / 6] = *(buf + i);
    ////    vVec[i - sz * 5 / 6 + 1] = *(buf + i);
    ////    vVec[i - sz * 5 / 6 + frame_width] = *(buf + i);
    ////    vVec[i - sz * 5 / 6 + frame_width + 1] = *(buf + i);
    ////}

    ////for (int i = sz * 2 / 3; i < sz; i += 2) {
    ////    uVec[i - sz * 2 / 3] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + 1] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + frame_width] = *(buf + i);
    ////    uVec[i - sz * 2 / 3 + frame_width + 1] = *(buf + i);

    ////    vVec[i - sz * 2 / 3] = *(buf + i + 1);
    ////    vVec[i - sz * 2 / 3 + 1] = *(buf + i + 1);
    ////    vVec[i - sz * 2 / 3 + frame_width] = *(buf + i + 1);
    ////    vVec[i - sz * 2 / 3 + frame_width + 1] = *(buf + i + 1);
    ////}
    ////float i = 0.0;
    ////while (i < size) {
    ////    if (trunc(i) == i) {
    ////        yVec.push_back(buf[(int)i]);
    ////        uint8_t uv = buf[(int)(i + 1)];
    ////        uVec.push_back((uv & 0xf0) >> 6);
    ////        vVec.push_back((uv & 0x30) >> 4);
    ////    }
    ////    else {
    ////        short yuv = (*(short*)((buf + (int)i))) & 0x0fff;
    ////        yVec.push_back((uint8_t)(yuv >> 4));
    ////        uVec.push_back((uint8_t)((yuv & 0x000f) >> 2));
    ////        vVec.push_back((uint8_t)(yuv & 0x0003));
    ////    }
    ////    i += 1.5;
    ////}


    //for (int i = 0; i < yVec.size(); ++i) {
    //    float r = yVec.at(i) + 1.402 * (vVec.at(i / 4) - 128),
    //        g = yVec.at(i) - 0.344 * (uVec.at(i / 4) - 128) - 0.714 * (vVec.at(i / 4) - 128),
    //        b = yVec.at(i) + 1.772 * (uVec.at(i / 4) - 128);



    //    if (r < 0) r = 0;
    //    if (r > 255) r = 255;
    //    if (g < 0) g = 0;
    //    if (g > 255) g = 255;
    //    if (b < 0) b = 0;
    //    if (b > 255) b = 255;
    //    new_buf.push_back((uint8_t)r);
    //    new_buf.push_back((uint8_t)g);
    //    new_buf.push_back((uint8_t)b);
    //}

    //uint8_t* newbuf = (uint8_t*)new_buf.data();
    //GLFWwindow* window;

    ///* Initialize the library */
    //if (!glfwInit())
    //    return -1;

    ///* Create a windowed mode window and its OpenGL context */
    //window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    //if (!window)
    //{
    //    glfwTerminate();
    //    return -1;
    //}

    ///* Make the window's context current */
    //glfwMakeContextCurrent(window);

    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    /* Render here */
    //    glClear(GL_COLOR_BUFFER_BIT);
    //    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    //    glBegin(GL_QUADS);
    //    glColor3f(1.0f, 0.0, 0.0);
    //    glVertex2i(0, 0);
    //    glVertex2i(1, 0);
    //    glVertex2i(1, 1);
    //    glVertex2i(0, 1);
    //    glEnd();

    //    /* Swap front and back buffers */
    //    glfwSwapBuffers(window);

    //    /* Poll for and process events */
    //    glfwPollEvents();
    //}

    //glfwTerminate();

    GLFWwindow* window;

    if (!glfwInit()) {
        printf("Couldn't init GLFW\n");
        return 1;
    }

    window = glfwCreateWindow(frame_width, frame_height, "POC Success", NULL, NULL);
    if (!window) {
        printf("Couldn't open window\n");
        return 1;
    }

    glfwMakeContextCurrent(window);

    // Generate texture
    GLuint tex_handle;
    glGenTextures(1, &tex_handle);
    glBindTexture(GL_TEXTURE_2D, tex_handle);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up orphographic projection
        int window_width, window_height;
        glfwGetFramebufferSize(window, &window_width, &window_height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, window_width, window_height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);

        glBindTexture(GL_TEXTURE_2D, tex_handle);
       
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame_width, frame_height, 0, GL_RGB, GL_UNSIGNED_BYTE, buf);

        // Render whatever you want
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex_handle);
        glBegin(GL_QUADS);
        const int offset = 0;
        glTexCoord2d(0, 0); glVertex2i(offset, offset);
        glTexCoord2d(1, 0); glVertex2i(frame_width + offset, offset);
        glTexCoord2d(1, 1); glVertex2i(frame_width + offset,frame_height + offset);
        glTexCoord2d(0, 1); glVertex2i(offset, frame_height+ offset);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}


