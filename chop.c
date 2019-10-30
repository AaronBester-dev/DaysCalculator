

int chop(char *line){

if (line[sizeof(line)-1]) == "\\" && line[sizeof(line)] == "n" {
  line[sizeof(line)-1] = "" && line[sizeof(line)] = "";
  return(0);
}
else{
  return(-1);
}

}
