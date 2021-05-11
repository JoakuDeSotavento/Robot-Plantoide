// una linea debajo y una por arriba
// que no supere un grosor
// proporsionar

smooth();

PVector[] robot;
String[] lines;

float modW = 0.07;
float modCoord = 40;
float eDiam = 200;

background(255);
size(1920, 1080);


String archivoCoord = "DATALOG.TXT";
lines = loadStrings(archivoCoord);

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
  int[] coord = int(split(lines[i], ','));
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



beginShape();
stroke(0);
strokeWeight(2);

noFill();
for (int i = 0; i < robot.length-1; i++) {
  ////////////////////// aqui
  //robot[i].x = constrain(robot[i].x, 0, width);
  //robot[i].y = constrain(robot[i].y, 0, height);
  float coordX = robot[i].x*modCoord;
  float coordY = robot[i].y*modCoord;
  if(coordX > width/2) {coordX =  coordX - width;
  }else if(coordX < -width/2) {coordX =  width/2 - (coordX-width);}
  if(coordY > height/2) {coordY = coordY - height;
  }else if(coordY < - height/2) {coordY =  height/2 - (coordY-height);}
  vertex(coordX, coordY);
}
endShape();
beginShape();
noFill();
stroke(70, 20);

strokeWeight(30);
for (int i = 0; i < robot.length-1; i++) {
  ////////////////////// aqui
  float coordX = robot[i].x*modCoord;
  float coordY = robot[i].y*modCoord;
  if(coordX > width/2) {coordX =  coordX - width;
  }else if(coordX < -width/2) {coordX =  width/2 - (coordX-width);}
  if(coordY > height/2) {coordY = coordY - height;
  }else if(coordY < - height/2) {coordY =  height/2 - (coordY-height);}
  vertex(coordX, coordY);
}
endShape();

//String fecha = str(hour()) + ":" + str(minute()) + ":" + str(second());

save("derivaPlantoide- " + archivoCoord + ".png");

//exit();
