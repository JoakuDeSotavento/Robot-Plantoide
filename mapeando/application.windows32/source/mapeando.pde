PVector[] robot;
String[] lines;

// ESTE ES EL FACTOR DE AUMENTO DEL GROSOR DE LA LINEA
// MANTENERLO DEBAJO DE "UNO"
float modW = 0.02;
// ESTE ES EL FACTOR DE AUMENTO DE LOS MOVIMIENTOS
// AUMENTARLO O DISMINUIRLO PARA HACER MAS GRANDE
// O PEQUEÑO EL ROBOT
float modCoord = 7;
//ESTE ES EL DIAMETRO DEL CIRCULO AMARILLO
float eDiam = 200;
// ESTA ES LA RESOLUCIÓN DE LA IMAGEN EN ANCHO Y ALTO 
//AGUAS PORQUE TAMBIEN ES LA PROPORCIÓ DEL ESPACIO
size(2190, 1050);

background(255);
smooth();
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



for (int i = 0; i < robot.length-1; i++) {
  strokeWeight(robot[i].z*modW);
  line(robot[i].x*modCoord, robot[i].y*modCoord, robot[i+1].x*modCoord, robot[i+1].y*modCoord);
}

saveFrame("derivaPlantoide-######.png");

//exit();
