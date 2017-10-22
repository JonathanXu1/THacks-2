var five = require('johnny-five');
var board = new five.Board();

board.on('ready', function() {
  var proximity = new five.Proximity({
    controller: "HCSR04",
    pin: 8
  });

  proximity.on("data", function() {
    console.log("Proxmity: ");
    console.log(" cm :", this.cm);
  });

  proximity.on("change", function() {
    console.log("The obstruction has moved.")
  });
});
