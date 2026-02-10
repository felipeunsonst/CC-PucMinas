//FELIPE COSTA UNSONST - 854155

// ---------- Módulo de Clock Base ----------
module clock (output reg clk);
  initial clk = 0;
  always #12 clk = ~clk; // Período total = 24
endmodule

// ---------- Exercício 01: pulse + trigger ----------
module pulse(output reg signal, input clock);
  always @ (clock) begin
    signal = 1;
    #3 signal = 0;
    #3 signal = 1;
    #3 signal = 0;
  end
endmodule

module trigger(output reg signal, input on, input clock);
  always @ (posedge clock & on) begin
    #60 signal = 1;
    #60 signal = 0;
  end
endmodule

module Guia_0901;
  wire clock;
  clock CLK1(clock);
  reg p;
  wire p1, t1;
  pulse pulse1(p1, clock);
  trigger trigger1(t1, p, clock);

  initial begin
    p = 0;
    $dumpfile("Guia_0901.vcd");
    $dumpvars(1, clock, p1, p, t1);
    #60  p = 1;
    #60  p = 0;
    #60  p = 1;
    #60  p = 0;
    #60  p = 1;
    #60  p = 0;
    #16 $finish;
  end
endmodule

// ---------- Exercício 02: pulses com diferentes períodos ----------
module pulse1(output reg signal, input clock);
  always @ (posedge clock) begin
    signal = 1;
    #4 signal = 0;
    #4 signal = 1;
    #4 signal = 0;
    #4 signal = 1;
    #4 signal = 0;
  end
endmodule

module pulse2(output reg signal, input clock);
  always @ (posedge clock) begin
    signal = 1;
    #5 signal = 0;
  end
endmodule

module pulse3(output reg signal, input clock);
  always @ (negedge clock) begin
    signal = 1;
    #15 signal = 0;
    #15 signal = 1;
  end
endmodule

module pulse4(output reg signal, input clock);
  always @ (negedge clock) begin
    signal = 1;
    #20 signal = 0;
    #20 signal = 1;
    #20 signal = 0;
  end
endmodule

module Guia_0902;
  wire clock;
  wire p1, p2, p3, p4;
  clock clk(clock);
  pulse1 pls1(p1, clock);
  pulse2 pls2(p2, clock);
  pulse3 pls3(p3, clock);
  pulse4 pls4(p4, clock);

  initial begin
    $dumpfile("Guia_0902.vcd");
    $dumpvars(1, clock, p1, p2, p3, p4);
    #480 $finish;
  end
endmodule

// ---------- Exercício 03: frequência = 1/3 ----------
module pulse_terco(output reg signal, input clock);
  reg [1:0] count = 0;
  always @(posedge clock) begin
    count = count + 1;
    if (count == 3) begin
      signal = ~signal;
      count = 0;
    end
  end
endmodule

module Guia_0903;
  wire clock, signal;
  clock clk(clock);
  pulse_terco p(signal, clock);

  initial begin
    $dumpfile("Guia_0903.vcd");
    $dumpvars(1, clock, signal);
    #480 $finish;
  end
endmodule

// ---------- Exercício 04: frequência = 4x ----------
module pulse_quadro(output reg signal, input clock);
  always @(posedge clock) begin
    signal = 1;
    #3 signal = 0;
  end
endmodule

module Guia_0904;
  wire clock, signal;
  clock clk(clock);
  pulse_quadro p(signal, clock);

  initial begin
    $dumpfile("Guia_0904.vcd");
    $dumpvars(1, clock, signal);
    #200 $finish;
  end
endmodule

// ---------- Exercício 05: 3 unidades na subida ----------
module pulse_3up(output reg signal, input clock);
  always @(posedge clock) begin
    signal = 1;
    #3 signal = 0;
  end
endmodule

module Guia_0905;
  wire clock, signal;
  clock clk(clock);
  pulse_3up p(signal, clock);

  initial begin
    $dumpfile("Guia_0905.vcd");
    $dumpvars(1, clock, signal);
    #240 $finish;
  end
endmodule

// ---------- Exercício 06: 4 unidades na descida ----------
module pulse_4down(output reg signal, input clock);
  always @(negedge clock) begin
    signal = 1;
    #4 signal = 0;
  end
endmodule

module Guia_0906;
  wire clock, signal;
  clock clk(clock);
  pulse_4down p(signal, clock);

  initial begin
    $dumpfile("Guia_0906.vcd");
    $dumpvars(1, clock, signal);
    #240 $finish;
  end
endmodule

// ---------- Exercício 07: 5 unidades com clock alto ----------
module pulse_5high(output reg signal, input clock);
  always @(clock) begin
    if (clock == 1) begin
      signal = 1;
      #5 signal = 0;
    end
  end
endmodule

module Guia_0907;
  wire clock, signal;
  clock clk(clock);
  pulse_5high p(signal, clock);

  initial begin
    $dumpfile("Guia_0907.vcd");
    $dumpvars(1, clock, signal);
    #240 $finish;
  end
endmodule
