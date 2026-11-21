#include "renderer.h"
#include "draw.h"
#include "globals.h"
#include "quaternion.hpp"
#include "vector3.hpp"
#include "vertex.hpp"
#include <cmath>
#include <vector>

void Renderer::update() {
  Renderer::updateViewM();
  Renderer::renderTriangle();
}

void Renderer::updateViewM() {
  Matrix4 T;
  T[0][3] = -gPlayer->camera.position.x;
  T[1][3] = -gPlayer->camera.position.y;
  T[2][3] = -gPlayer->camera.position.z;
  Matrix4 R = gPlayer->camera.rotation.toMatrix4().transposed();
  gPlayer->camera.viewM = R * T;
}

void Renderer::createProjectionM() {
  Matrix4 P;
  float tan_2fov = tan(static_cast<float>(kFOV) / 2);
  float aspect = static_cast<float>(kScreenWidth) / kScreenHeight;
  P[0][0] = 1.0f / (aspect * tan_2fov);
  P[1][1] = 1.0f / tan_2fov;
  P[2][2] = (kFarClipping + kNearClipping) / (kFarClipping - kNearClipping);
  P[3][3] = 0;
  P[3][2] = 1;
  P[2][3] =
      -((2 * kFarClipping * kNearClipping) / (kFarClipping - kNearClipping));
  gPlayer->camera.projectionM = P;
}

void Renderer::renderTriangle() {
  std::vector<Vertex> vert = gRoot->childs[0]->model.vertices;
  for (int i = 0; i < vert.size(); i++) {
    Vector4 v = gPlayer->camera.projectionM * gPlayer->camera.viewM *
                gRoot->childs[0]->modelMatrix * vert[i].position;
    vert[i].position = {v.x / v.w, v.y / v.w, v.z / v.w};
    vert[i].convertToScreenSpace(kScreenWidth, kScreenHeight);
  }
  DrawUtil::drawTrinagleOutlineVertexNDC(vert);
}
