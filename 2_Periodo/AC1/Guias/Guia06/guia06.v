//FELIPE COSTA UNSONST

module guia_06;
    reg x, y, z, w;
    wire f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    
    assign f1 = (~x & ~y & z) | (~x & y & ~z) | (~x & y & z) | (x & ~y & ~z);
    assign f2 = (~x & ~y & ~z) | (x & ~y & ~z) | (x & y & ~z); 
    assign f3 = (~x & ~y & z) | (~x & y & ~z) | (~x & y & z) | (x & y & z);
    assign f4 = (~x & ~y & z) | (~x & y & ~z) | (x & ~y & z) | (x & y & ~z); 
    assign f5 = (~x & ~y & ~z) | (~x & y & ~z) | (x & ~y & ~z) | (x & y & z);
    
    assign f6 = (x | y | z) & (~x | ~y | ~z) & (~x | y | z); 
    assign f7 = (x | y | ~z) & (~x | ~y | z) & (x | y | z);
    assign f8 = (x | ~y | z) & (~x | y | ~z) & (~x | y | z) & (~x | ~y | z); 
    
    assign f9 = (~x & ~y & w & z) | (~x & y & ~w & z) | (x & y & w & ~z); 
    
    assign f10 = (x | y | w | ~z) & (~x | ~y | w | z) & (x | ~y | w | z); 
    
    assign f11 = (~x & y & z) | (x & ~y & w) | (x & y & ~z); 
    
    assign f12 = (x | ~y | z) & (~x | y | ~w) & (x | ~y | ~z); 
    
    assign f13 = (x | y | z) & (~x | ~y | z) & (~x | ~y | z);
    
    assign f14 = (w & x & y & ~z) | (w & x & ~y & z) | (w & ~x & ~y & ~z) | (~w & ~x & y & ~z); 
    
    initial begin
        $display("x y z w | f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14");
        $monitor("%b %b %b %b | %b  %b  %b  %b  %b  %b  %b  %b  %b  %b  %b  %b", x, y, z, w, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14);
        
        for (integer i = 0; i < 16; i = i + 1) begin
            {x, y, z, w} = i;
            #10;
        end
        $finish;
    end
endmodule
