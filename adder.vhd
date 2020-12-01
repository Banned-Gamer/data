library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity adder is
  port(
    D   : in std_logic_vector(3 downto 0);
    pr, clr, clk : in std_logic;
    x   : out std_logic;
    y   : out std_logic_vector(3 downto 0)
    );
end adder;

architecture arc of adder is
    signal temp: std_logic_vector(3 downto 0);
  begin
    process(pr,clr,clk) begin
      if pr = '0' then
        temp <= "0000";
      elsif rising_edge(clk) then
        if clr = '1' then
          temp <= D;
        else
          if temp = "1111" then
            temp <= "0000";
            x <= '1';
          else
            temp <= temp+1;
            x <= '0';
          end if;
        end if;
      end if;
    end process;
    y <= temp;
end arc;      