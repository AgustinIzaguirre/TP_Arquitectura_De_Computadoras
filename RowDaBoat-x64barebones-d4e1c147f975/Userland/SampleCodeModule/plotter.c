#include <plotter.h>
#include <stdint.h>
#include <stdlib.h>
// #include <types.h>
extern uint64_t _int80(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);
  
	void draw_pixel_with_color(int x, int y,Color color){
      	uint64_t c=ColorToHexa(color);
        _int80(8,x,y,color.blue,color.green,color.red);//llamar a la SysCall que corresponde a pintar el pixel;
	}

	void draw_pixel(int x, int y){
    	_int80(8,x,y,0,0,0);//llamar a la Syscall que corresponde al pixel
  }


  void draw_horizontalLine(int x0, int x1, int y){
  	for(int i=x0; i<x1;i++){
      	draw_pixel(i,y);
    	}
 	}

 	void draw_verticalLine(int x, int y0, int y1){
    	for(int i=y0; i<y1;i++){
      	draw_pixel(x,i);
    	}
 	}

 	void draw_verticalTotalLine(int x){
    	draw_verticalLine(x,0,(int)getScreenHeight());
 	}

 	void draw_horizontalTotalLine(int y){
    	draw_horizontalLine(0,(int)getScreenWidht(),y);
 	}

  
  // void drawFunction(int a, int b, int c){
  //   int height= (int)getScreenHeight();
  //   int width = (int)getScreenWidht();
  //   drawAxis();
  //   double x=0;
  //   double y=0;
  //   double scale=0.01;
  //   for (int p=-500;p<500;p++){
  //     x=p*scale;
  //     y=a*x*x+b*x+c;
  //     y*= 100;
  //     draw_pixel(width/2 + p, height/2-y);
  //   }
  // }

  // void drawAxis(){
 	// 	int height=(int)getScreenHeight();
 	// 	int width=(int)getScreenWidht();
 	// 	for(int i=0;i<height;i++){
 	// 		draw_pixel(i,width/2);
 	// 	}
 	// 	for (int j=0; j<width;j++){
 	// 		draw_pixel(height/2,j);
 	// 	}
 	// 	//faltaria agregar los valores.    
  //     int x0=width/2;
  //     draw_verticalTotalLine(x0);
  //     int y0=height/2;
  //     draw_horizontalTotalLine(y0);
  //   // draw_char_position('1',width/2+100,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('2',width/2+200,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('3',width/2+300,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('4',width/2+400,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('5',width/2+500,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('1',width/2-100,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('2',width/2-200,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('3',width/2-300,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('4',width/2-400,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('5',width/2-500,height/2 +CHAR_HEIGHT);
  //   // draw_char_position('1',width/2-CHAR_WIDTH,height/2 -100);
  //   // draw_char_position('2',width/2-CHAR_WIDTH,height/2 -200);
  //   // draw_char_position('3',width/2-CHAR_WIDTH,height/2 -300);
  //   // draw_char_position('4',width/2-CHAR_WIDTH,height/2 -400);
  //   // draw_char_position('5',width/2-CHAR_WIDTH,height/2 -500); 
  //   // draw_char_position('1',width/2-CHAR_WIDTH,height/2 +100);
  //   // draw_char_position('2',width/2-CHAR_WIDTH,height/2 +200);
  //   // draw_char_position('3',width/2-CHAR_WIDTH,height/2 +300);
  //   // draw_char_position('4',width/2-CHAR_WIDTH,height/2 +400);
  //   // draw_char_position('5',width/2-CHAR_WIDTH,height/2 +500);
 
 	// }


  void drawFunction(int a, int b, int c){
      int height= (int)getScreenHeight();
      int width = (int)getScreenWidht();
      drawAxis();
      double x=0;
      double y=0;
      double scale=0.01;
      for (int p=-500;p<500;p++){
         x=p*scale;
         y=a*x*x+b*x+c;
         y*= 100;
         draw_pixel(width/2 + p, height/2-y);
      }
   }

   // void drawFunction(int a, int b, int c){
   //    int height= mode_info->height;
   //    int width = mode_info->width;
   //    drawAxis();
   //    double x=0;
   //    double y=0;
   //    double scale=0.01;
   //    for (int p=-500;p<500;p++){
   //       x=p*scale;
   //       y=a*x*x+b*x+c;
   //       y*= 100;
   //       draw_pixel(width/2 + p, height/2-y);
   //    }
   // }

   void drawAxis(){
      int height= (int)getScreenHeight();
      int width = (int)getScreenWidht();
      int x0=width/2;
      draw_verticalTotalLine(x0);
      int y0=height/2;
      draw_horizontalTotalLine(y0);
      _int80(10,'1',width/2+100,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'2',width/2+200,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'3',width/2+300,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'4',width/2+400,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'5',width/2+500,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'1',width/2-100,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'2',width/2-200,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'3',width/2-300,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'4',width/2-400,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'5',width/2-500,height/2 +CHAR_HEIGHT,0,0);
      _int80(10,'1',width/2-CHAR_WIDTH,height/2 -100,0,0);
      _int80(10,'2',width/2-CHAR_WIDTH,height/2 -200,0,0);
      _int80(10,'3',width/2-CHAR_WIDTH,height/2 -300,0,0);
      _int80(10,'4',width/2-CHAR_WIDTH,height/2 -400,0,0);
      _int80(10,'5',width/2-CHAR_WIDTH,height/2 -500,0,0); 
      _int80(10,'1',width/2-CHAR_WIDTH,height/2 +100,0,0);
      _int80(10,'2',width/2-CHAR_WIDTH,height/2 +200,0,0);
      _int80(10,'3',width/2-CHAR_WIDTH,height/2 +300,0,0);
      _int80(10,'4',width/2-CHAR_WIDTH,height/2 +400,0,0);
      _int80(10,'5',width/2-CHAR_WIDTH,height/2 +500,0,0);
   }
    
  void cls(){
     	_int80(9,0,0,0,0,0);
 	}

  uint64_t getScreenWidht(){
    return _int80(11,0,0,0,0,0);
  }

  uint64_t getScreenHeight(){
    return _int80(11,1,0,0,0,0);
  }


Color hexaToColor(uint64_t color){
  Color c = {.red = (color & RED_MASK) >>16, .green = (color & GREEN_MASK) >> 8, .blue = color & BLUE_MASK};
  return c;
}

uint64_t ColorToHexa(Color color){
  uint64_t hexColor= color.red<<16|color.green<<8|color.blue;
  return hexColor;
}
