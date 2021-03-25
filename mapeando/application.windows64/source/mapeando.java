import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class mapeando extends PApplet {
  public void setup() {
PVector[] robot;
String[] lines;

// ESTE ES EL FACTOR DE AUMENTO DEL GROSOR DE LA LINEA
// MANTENERLO DEBAJO DE "UNO"
float modW = 0.02f;
// ESTE ES EL FACTOR DE AUMENTO DE LOS MOVIMIENTOS
// AUMENTARLO O DISMINUIRLO PARA HACER MAS GRANDE
// O PEQUEÑO EL ROBOT
float modCoord = 7;
//ESTE ES EL DIAMETRO DEL CIRCULO AMARILLO
float eDiam = 200;
// ESTA ES LA RESOLUCIÓN DE LA IMAGEN EN ANCHO Y ALTO 
//AGUAS PORQUE TAMBIEN ES LA PROPORCIÓ DEL ESPACIO


background(255);

lines = loadStrings("DATALOG.TXT");

translate(width/2, height/2);

int pasos = lines.length;
robot = new PVector[pasos];
println("there are " + lines.length + " lines");
//int[] nums = int(split(numbers, ' '));
for (int i = 0; i < robot.length; i++) {
  robot[i] = new PVector(0, 0, 0);
}
for (int i = 0; i < lines.length; i++) {
  println(lines[i]);
  int[] coord = PApplet.parseInt(split(lines[i], ','));
  robot[i].set(coord[0], coord[1], coord[2]);
}

println("there are " + robot.length + " robot steps");
for (int i = 0; i < robot.length; i++) {
  println(robot[i]);
}

pushStyle();
noStroke();
fill(255, 255, 0);
ellipse(0, 0, eDiam, eDiam);
popStyle();



for (int i = 0; i < robot.length-1; i++) {
  strokeWeight(robot[i].z*modW);
  line(robot[i].x*modCoord, robot[i].y*modCoord, robot[i+1].x*modCoord, robot[i+1].y*modCoord);
}

saveFrame("derivaPlantoide-######.png");

//exit();
    noLoop();
  }

  public void settings() { 
size(2190, 1050); 
smooth(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--stop-color=#cccccc", "mapeando" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
