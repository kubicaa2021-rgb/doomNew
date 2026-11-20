#ifndef RENDERER_H
#define RENDERER_H
class Renderer {
public:
  static void update();
  static void createProjectionM();

private:
  static void updateViewM();
  static void renderTriangle();
};
#endif // !RENDERER_H
