//FELIPE COSTA UNSONST
//854155

module Guia_0105; 
  reg [7:0] ascii_puc[0:8];
  reg [7:0] ascii_2025[0:6];
  reg [7:0] ascii_belo[0:20];
  integections 
  initial 
  begin : main 
    $display("Guia_0104 - Hexadecimal
    ascii_puc[0] = "P";
    ascii_puc[1] = "U";
    ascii_puc[2] = "C";
    ascii_puc[3] = "-";
    ascii_puc[4] = "M";
    ascii_puc[5] = "i";
    ascii_puc[6] = "n";
    ascii_puc[7] = "a";
    ascii_puc[8] = "s";
    $display("PUC-Minas = ");
    for (i = 0; i < 9; i = i + 1) begin
      $display("%2h", ascii_puc[i]);
-01" to ASCII in Hexadecimal
    ascii_2025[0] = "2";
    ascii_2025[1] = "0";
    ascii_2025[2] = "2";
    ascii_2025[3] = "5";
    ascii_2025[4] = "-";
    ascii_2025[5] = "0";
    ascii_2025[6] = "1";
    $display("2025-01 = ");
    for (i = 0; i < 7; i = i + 1) begin
      $display("%2h", as"Belo Horizonte - M.G." to ASCII in Binary
    ascii_belo[0] = "B";
    ascii_belo[1] = "e";
    ascii_belo[2] = "l";
    ascii_belo[3] = "o";
    ascii_belo[4] = " ";
    ascii_belo[5] = "H";
    ascii_belo[6] = "o";
    ascii_belo[7] = "r";
    ascii_belo[8] = "i";
    ascii_belo[9] = "z";
    ascii_belo[10] = "o";
    ascii_belo[11] = "n";
    ascii_belo[12] = "t";
    ascii_belo[13] = "e";
    ascii_belo[14] = " ";
    ascii_belo[15] = "-";
    ascii_belo[16] = " ";
    ascii_belo[17] = "M";
    ascii_belo[18] = ".";
    ascii_belo[19] = "G";
    ascii_belo[20] = ".";
    $display("Belo Horizonte - M.G. = ");
    for (i = 0; i < 21; i = i + 1) begelo[i]);
    end
    $display();

    // Converting octal to ASCII
    $display("156 157 1'o157, 8'o151, 8'o164, 8'o145);

    // Converting hexadecimal to ASCII
    $display("4D 61 6E 68 61 (16) = %c%c%c%c%c", 8'h4D, 8'h61, 8'h6E, 8'h68, 8'h61);
  end // main 
endmodule // Guia_0104
