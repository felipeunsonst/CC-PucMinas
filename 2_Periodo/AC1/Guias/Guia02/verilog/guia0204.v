// FELIPE COSTA UNSONST
// 854155

module Guia_0204;
  real x;
  integer y;
  reg [15:0] b;

  initial begin
    $display("Guia_0204 - Tests");

    x = 0.231;
    b = 0;
    y = 15;
    $display("Converting 0.231 from base 4 to base 2");
    while (x > 0 && y >= 0) begin
      if (x * 4 >= 1) begin
        b[y] = 1;
        x = x * 4 - 1;
      end else begin
        b[y] = 0;
        x = x * 4;
      end
      $display("b = 0.%16b", b);
      y = y - 1;
    end

    x = 0.5C2;
    b = 0;
    y = 15;
    $display("Converting 0.5C2 from base 16 to base 4");
    while (x > 0 && y >= 0) begin
      if (x * 16 >= 1) begin
        b[y] = 1;
        x = x * 16 - 1;
      end else begin
        b[y] = 0;
        x = x * 16;
      end
      $display("b = 0.%16b", b);
      y = y - 1;
    end

    x = 0.735;
    b = 0;
    y = 15;
    $display("Converting 0.735 from base 8 to base 2");
    while (x > 0 && y >= 0) begin
      if (x * 8 >= 1) begin
        b[y] = 1;
        x = x * 8 - 1;
      end else begin
        b[y] = 0;
        x = x * 8;
      end
      $display("b = 0.%16b", b);
      y = y - 1;
    end

    x = 6.2345;
    b = 0;
    y = 15;
    $display("Converting 6.2345 from base 8 to base 4");
    while (x > 0 && y >= 0) begin
      if (x * 8 >= 1) begin
        b[y] = 1;
        x = x * 8 - 1;
      end else begin
        b[y] = 0;
        x = x * 8;
      end
      $display("b = 0.%16b", b);
      y = y - 1;
    end
	  
    x = B.A5E;
    b = 0;
    y = 15;
    $display("Converting B.A5E from base 16 to base 4");
    while (x > 0 && y >= 0) begin
      if (x * 16 >= 1) begin
        b[y] = 1;
        x = x * 16 - 1;
      end else begin
        b[y] = 0;
        x = x * 16;
      end
      $display("b = 0.%16b", b);
      y = y - 1;
    end
  end 
endmodule 
