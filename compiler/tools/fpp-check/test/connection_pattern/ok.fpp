passive component Health {

}
passive component C {

}
instance $health: Health base id 0x100
instance c: C base id 0x200
topology T {
  instance $health
  instance c
  health connections instance $health {
    c
  }
}