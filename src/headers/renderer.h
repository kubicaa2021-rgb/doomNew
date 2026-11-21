#ifndef RENDERER_H
#define RENDERER_H
class Renderer {
public:
  static void update();
  static void createProjectionM();

private:
  static void updateViewM();
  static void renderObject();
};
#endif // !RENDERER_H
