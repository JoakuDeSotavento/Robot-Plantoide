int checkIR() {
  // movimientos si un solo sensor percibe algo
  if (cmArray[0] <= umbral) {
    // si el sensor forntal detecta, da marcha a trás
    estado = 1;
  } else if (cmArray[1] <= umbral) {
    // si el sensor izquierdo detecta, gira a la derecha y avanza
    estado = 2;
  } else if (cmArray[2] <= umbral) {
    // si el sensor trasero detecta, da marcha hacia delante
    estado = 5;
  }  else if (cmArray[3] <= umbral) {
    // si el sensor trasero detecta, da marcha hacia delante
    estado = 3;
  } else if (cmArray[4] <= umbral) {
    // si el sensor trasero detecta, da marcha hacia delante
    estado = 6;
  } else if (cmArray[5] <= umbral) {
    // si el sensor derecho detecta, gira a la izquierda y avanza
    estado = 4;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // movimientos si dos sensores perciben cosas
  } else if ((cmArray[0] <= umbral) && (cmArray[1] <= umbral)) {
    // si los sensores frontales y el izquierdo, gira 45 grados a la izquierda y da marcha atrás
    estado = 5;
  } else if (cmArray[0] <= umbral && cmArray[2] <= umbral) {
    // si los sensores frontales y trasero, gira 180 a derecha o izquierda y da marcha delante o atrás
    estado = 6;
  } else if (cmArray[0] <= umbral && cmArray[3] <= umbral) {
    // Si los sensores frontal y derecho, gira 45 a la izquierda y da marcha atrás
    estado = 7;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  } else if (cmArray[2] <= umbral && cmArray[1] <= umbral) {
    // si los sensores izquierdo y el trasero, gira 45 grados derecha y avanza
    estado = 8;
  } else if (cmArray[2] <= umbral && cmArray[3] <= umbral) {
    // si los sensores trasero y derecho, gira 45 izquierda y avanza
    estado = 9;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  } else if (cmArray[1] <= umbral && cmArray[3] <= umbral) {
    // si los sensores izquierdo y derecho, avanza o retrocede doble velocidad
    estado = 10;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  } else if (cmArray[0] <= umbral && cmArray[1] <= umbral && cmArray[3] <= umbral) {
    // si los sensores laterales y forntal, da marcha atrás al doble de la velocidad
    estado = 11;
  } else if (cmArray[1] <= umbral && cmArray[2] <= umbral && cmArray[3] <= umbral) {
    // si los sensores trasero y laterales, da marcha delante al doble de la velocidad
    estado = 6;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  } else if (cmArray[0] <= umbral && cmArray[1] <= umbral && cmArray[2] <= umbral) {
    // si los sensores izquierdo, frontal y trasero, gira 90 grados derecha y avanza doble velocidad
    estado = 13;
  } else if (cmArray[0] <= umbral && cmArray[3] <= umbral && cmArray[2] <= umbral) {
    // si los sensores derecho, frontal y trasero, gira 90 grados izquierda y avanza doble velocidad
    estado = 14;
  } else {
    estado = 0;
  }
}
