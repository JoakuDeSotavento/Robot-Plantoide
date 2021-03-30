PVector[] robot;
String[] lines;

float modW = 0.08;
float modCoord = 7;

float eDiam = 200;

background(255);
size(1920, 1080);
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
  stroke(0, 50);
  strokeWeight(robot[i].z*modW);
  line(robot[i].x*modCoord, robot[i].y*modCoord, robot[i+1].x*modCoord, robot[i+1].y*modCoord);
}

saveFrame("derivaPlantoide-######.png");

//exit();
