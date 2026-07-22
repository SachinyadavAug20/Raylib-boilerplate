#include <raylib.h>

const int windowWidth=600;
const int windowHeight=600;
const int ballSpeed=10;
int main(){
  int ballX=windowWidth/2;
  int ballY=windowHeight/2;
  Color green={20,160,133,255};

  InitWindow(windowWidth, windowHeight, "Raylib");// width,height,title
  SetTargetFPS(60); 
  // Game loop (will run 60 times a second)
  while (WindowShouldClose()==false) {
    // 1.Event handling
    if(IsKeyDown(KEY_RIGHT)){
      ballX+=ballSpeed;
    }else if(IsKeyDown(KEY_LEFT)){
      ballX-=ballSpeed;
    }else if(IsKeyDown(KEY_DOWN)){
      ballY+=ballSpeed;
    }else if(IsKeyDown(KEY_UP)){
      ballY-=ballSpeed;
    }
    // 2.updating positions
    // 3.drawing
    BeginDrawing();
    ClearBackground(green);
    DrawCircle(ballX,ballY, 20, WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
