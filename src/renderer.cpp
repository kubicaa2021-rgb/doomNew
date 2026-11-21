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
  Renderer::renderObject();
}

void Renderer::updateViewM() {
  Matrix4 T; // {{{
  T[0][3] = -gPlayer->camera.position.x;
  T[1][3] = -gPlayer->camera.position.y;
  T[2][3] = -gPlayer->camera.position.z;
  Matrix4 R = gPlayer->camera.rotation.toMatrix4().transposed();
  gPlayer->camera.viewM = R * T;
} // }}}

void Renderer::createProjectionM() {
  Matrix4 P; // {{{
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
} // }}}

void Renderer::renderObject() {
  Object *O = gRoot->childs[0];

  Matrix4 MVP = gPlayer->camera.projectionM * gPlayer->camera.viewM *
                gRoot->childs[0]->modelMatrix;

  std::vector<Vector4> clip;

  for (const Vertex &v : O->model.vertices) {
    clip.push_back(MVP * v.position);
  }

  // Until here you can compute with vertices
  // After that you need to make it use triangles from indicies

  // Add near plane clipping
  std::vector<Vector4> poly;
  for (int i = 0; i < clip.size(); i++) {
    const Vector4 &A = clip[i];
    const Vector4 &B =
        clip[(i + 1) % clip.size()]; // when it is more then size set it to 0
    const float Ad = A.w - kNearClipping;
    const float Bd = B.w - kNearClipping;
    if (Ad >= 0)
      poly.push_back(A);

    if ((Ad >= 0) != (Bd >= 0)) {
      float t = (kNearClipping - B.w) / (A.w - B.w);
      poly.push_back({B.x + (A.x - B.x) * t, B.y + (A.y - B.y) * t,
                      B.z + (A.z - B.z) * t, B.w + (A.w - B.w) * t});
    }
  }

  // Fully behind camera
  if (poly.size() < 3)
    return;

  // Creating vertex and perspetive divide
  std::vector<Vertex> verts;
  for (const Vector4 &vec : poly) {
    Vertex v;
    v.position = {vec.x / vec.w, vec.y / vec.w, vec.z / vec.w, vec.w};
    v.convertToScreenSpace(kScreenWidth, kScreenHeight);
    verts.push_back(v);
  }
  // Change so it renders triangles and not some shit when obj has more vertices
  DrawUtil::drawPolygonOutline(verts);
}
