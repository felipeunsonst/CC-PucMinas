//FELIPE COSTA UNSONST
//854155

module Guia_0203;
  real x;
  integer y;
  reg [7:0] b;

  initial begin
    $display("Guia_0203 - Tests");

    x = 0.011010; 
    b = 0;
    y = 7;
    $display("Converting 0.011010 from base 2 to base 4");
    while (x > 0 && y >= 0) begin
      if (x * 2 >= 1) begin
        b[y] = 1;
        x = x * 2.0 - 1.0;
      end else begin
        b[y] = 0;
        x = x * 2.0;
      end
      $display("b = 0.%8b", b);
      y = y - 1;
    end

    x = 0.100011; 
    b = 0;
    y = 7;
    $display("Converting 0.100011 from base 2 to base 8");
    while (x > 0 && y >= 0) begin
      if (x * 2 >= 1) begin
        b[y] = 1;
        x = x * 2.0 - 1.0;
      end else begin
        b[y] = 0;
        x = x * 2.0;
      end
      $display("b = 0.%8b", b);
      y = y - 1;
    end

    x = 0.100101; 
    b = 0;
    y = 7;
    $display("Converting 0.100101 from base 2 to base 16");
    while (x > 0 && y >= 0) begin
      if (x * 2 >= 1) begin
        b[y] = 1;
        x = x * 2.0 - 1.0;
      end else begin
        b[y] = 0;
        x = x * 2.0;
      end
      $display("b = 0.%8b", b);
      y = y - 1;
    end

    x = 1.111001; 
    b = 0;
    y = 7;
    $display("Converting 1.111001 from base 2 to base 8");
    while (x > 0 && y >= 0) begin
      if (x * 2 >= 1) begin
        b[y] = 1;
        x = x * 2.0 - 1.0;
      end else begin
        b[y] = 0;
        x = x * 2.0;
      end
      $display("b = 0.%8b", b);
      y = y - 1;
    end

    x = 1011.1101; 
    b = 0;
    y = 7;
    $display("Converting 1011.1101 from base 2 to base 16");
    while (x > 0 && y >= 0) begin
      if (x * 2 >= 1) begin
        b[y] = 1;
        x = x * 2.0 - 1.0;
      end else begin
        b[y] = 0;
        x = x * 2.0;
      end
      $display("b = 0.%8b", b);
      y = y - 1;
    end
  end 
endmodule 
