# handwired/scylla

![handwired/scylla](imgur.com image replace me!)

This is a handwired keyboard, it is 3D printed from the [BastardKb Scylla](https://github.com/Bastardkb/Scylla) CAD files.

But hardware was sourced from [SplitKb](https://splitkb.com) since they had both microcontrollers, TRRS jacks, diodes, and switches.

If I where to do it over again I would not have 3D printed the case but instead bought the [Scylla kit](https://bastardkb.com/product/scylla-kit/).

## Layout

The layout is based on qwerty but it  make use of [home row mods](https://precondition.github.io/home-row-mods)
which frees up a lot of options. It should work well with vim and C based languages and it should be adaptable to work with smaller keyboards.

To figure out how important a symbol is we look at frequency of symbols in [English text](http://www.cs.umd.edu/hcil/trs/2013-17/2013-17.pdf) and in [C-code](https://stackoverflow.com/a/62766162).
Then I use that information toghether with my own experience to decide which symbols make my very important symbol (V.I.S) list.

| C code | Hz        | Twitter| Hz        | V.I.S |
|--------|-----------|--------|-----------|--------|
| space  | 15.083    | .      | 1.694     | ,      |
| _      | 2.550     | @      | 1.221     | .      |
| *      | 1.769     | !      | 0.940     | ;      |
| ,      | 1.565     | '      | 0.550     | :      |
| .      | 1.512     | _      | 0.527     | '      |
| )      | 1.373     | ,      | 0.401     | (      |
| (      | 1.372     | :      | 0.381     | /      |
| ;      | 1.276     | #      | 0.377     | "      |
| -      | 1.176     | ?      | 0.338     | -      |
| =      | 1.039     | "      | 0.205     | =      |
| /      | 0.718     | -      | 0.185     | ?      |
| >      | 0.587     | )      | 0.181     |        |
| "      | 0.376     | <      | 0.095     |        |
| {      | 0.303     | >      | 0.094     |        |
| &      | 0.237     | (      | 0.089     |        |
| }      | 0.210     | *      | 0.075     |        | 
| :      | 0.192     | &      | 0.055     |        | 
| +      | 0.182     | ;      | 0.048     |        | 
| #      | 0.175     | /      | 0.042     |        | 
| ]      | 0.163     | ^      | 0.017     |        | 
| [      | 0.163     | =      | 0.016     |        | 
| <      | 0.118     | ~      | 0.013     |        | 
| %      | 0.105     | $      | 0.010     |        | 
| !      | 0.102     | |      | 0.007     |        | 
| '      | 0.101     | \      | 0.005     |        | 
| |      | 0.098     | +      | 0.005     |        | 
| ?      | 0.022     | %      | 0.004     |        | 
| @      | 0.009     | ]      | 0.002     |        | 
| $      | 0.005     | {      | 0.002     |        | 
| ^      | 0.003     | }      | 0.002     |        | 
| ~      | 0.002     | [      | 0.001     |        | 

Then we look at finger strength and finger travel distance to decide which finger should press which symbol.

|       | Pinky| Ring  | Middle| Index |      |
|-------|------|-------|-------|-------|------|
|   5   |  3.6 |  2.4  |  1.8  |  2.2  |  3.5 |
|   4   |  1.6 |  1.2  |  1    |  1    |  3   |
|   6   |  3.4 |  2.6  |  2.2  |  1.8  |  4   |

|       | Index | Middle| Ring  | Pinky |      |
|-------|-------|-------|-------|-------|------|
|   3.5 |  2.2  |  1.8  |  2.4  |  3.6  |  5   |
|   3   |  1    |  1    |  1.2  |  1.6  |  4   |
|   4   |  1.8  |  2.2  |  2.6  |  3.4  |  6   |

The final layout gives us something close to US qwerty but with a custom symbol layer.

Base layer:

|  +   |  q  |  w   |  e   |  r   |  t   |
|  "   |  a  |  s   |  d   |  f   |  g   |
|      |  z  |  x   |  c   |  v   |  b   |

|  y   |  u  |  i   |  o   |  p   |  -   |
|  h   |  j  |  k   |  l   |  ;   |  '   |
|  n   |  m  |  ,   |  .   |  /   |      |

Symbol layer:

|      |  !  |  @   |  #   |  $   |  %   |
|      |  \  |  )   |  =   |  (   |      |
|      |     |      |      |  `   |      |


|  ^  |  &   |  *   |  \|  |      |      |
|     |  -   |  {   |  +   |  }   |      |
|     |  _   |  [   |  ~   |   ]  |      |


