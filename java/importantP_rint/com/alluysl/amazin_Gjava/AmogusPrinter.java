package com.alluysl.amazin_Gjava;

import java.util.HashMap;
import java.util.Optional;
import java.util.function.Function;

// https://manytools.org/hacker-tools/convert-images-to-ascii-art/

public interface AmogusPrinter {
	
	StringBuffer amazin_Gline(boolean which);
	
	String makeStringToPrint(String inputString, Function<Character, Character> charMapper);

	default void print() {
		StringBuffer sbuf = new StringBuffer("PPPPPPPPPPPPXXXpp;PPPaaaaaa||||||||||||||||PPPP|PPhhhPaaaa|aaa|||a|(XXX(\\(\\|aaaa\nPPPPP(|a|(h\\\\(|PPp|PP|aaaa|||||aaaaaaaaa||||||aPPPPPPPaaaa|||aPaP((\\\\;Xhah\\|aaaa\nPPPPP(aa|\\ahXX;;XpPhPPPa|aa||||aaaaaaa|||||||a||P|PPP|||||hPPPhhhPPhh(((hPXXaaaa\nPPPPP|hhhhPPPh((\\\\(\\hhhhhhP|||||a|aaa|aa|||aa|||||||||||||PhhhP|PP||PPh\\Phhaaaaa\nPPPPhPPPPaP|PPhhhh\\(hhh((hh||aaaaaaaaaa||a||||a||||PP||||||PPPPPP|||PPhhaaaaaaaa\nhhhhhhhhhhhPPhhhh(((((((((((||||aaaaaaaaaaa|aaa||hPhPPPPPPPP|aaa||||Ph(|||||||||\nhhhhh(hh((|aa|(hP(\\\\\\\\\\\\|||Pa|;;;;PPaa|aaaaa|a;\\(((((h(hhhh(|aPaaah(;p|\\PPPPPPPP\nPPP|||||||P(\\X;;(a|(\\\\PP|PPPPPa(;ppp;\\aaaa||Pp\t;XX\\\\\\\\\\\\ppphPPPPaa||||X;(hhhhhhh\n\\\\\\\\\\\\\\\\\\\\\\\\X\\\\\\XXXXXPaaaa||aahhh|P\\\\aaaa||ah|pX\\\\\\(((((hhhPP|||a|(X;;Xphhhhhhhh\n\\XX\\X\\\\\\\\XX\\\\\\\\X\\\\XX|X|PPph\\PPP||||Xaa||||aPPhPPh(;;;;XXXXXXXXXX\\\\\\\\\\\\\\(((((((((\nXX\\\\\\\\\\\\(((((((((((\\|\\PXp;Pp|PaP||||aa|aPPhaX||PP(\t\t\t\thXXXXXXXXX\\XXX\\\\X\\\\\\\\\\\\\\\\\\\n\\\\(((((((((hhhhhhh\\XX;P|P\\\\(P|PP|PPP|||||||Pa|a||PPPPPPh\tX\\\\\\\\XXXX\\\\\\\\\\XX\\\\\\\\\\\\\\\n\\\\\\\\(((((hh(hhhhhhPPaXX(P(|h|XPPPp\t\t\t\tPPPPP|aaaaPhh(haaP(\\\\\\\\X\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
		StringBuilder sbui = new StringBuilder('\n' + "XXXXXXXXXX\\XXXXX\\X\\\\X\\\\\\\\\\\\\\\\\\\\((((((\\\\\\\\(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\(\\\\\\\\\\");
		String s = new String("||||||||||||||||||||||a|||||aa|aa|a|aaaaaaaaaaaaaaaaaaaaaaaa|||||||||a||||||||||\n||||||||||||||||||||||a|||||||a|aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa|a|||||||||||||||\n||||||||||||||||||||||||||||||aaa|aaaaaaaaaaaaaaaaaaaaaaaaa|aa|aa|||||||||||||||\n|||||||||||||||||||||||||||||||aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa||a||a|||||||||||||\n|||||||||||||||||||||||||||||||a|aaaaaaaaaaaaaaaaaaaaaaaaaa|aaaaaa||||||||||||||\n|||||||||||||||||||||||||||||aa|aaaa|aaaaaaaaaaaaaaaaaaaaaaa|aa||aa|||||||||||||\n||||||||||||||||||||||||||||||||a|aaaaaaaaa|||||||aaaaaaaaaaaaaa|a||||||||||||||\n||||||||||||||||||||||||||||||||||a|a|||||h;X;XXhPPP||aaaaaaaaaaa|aaa||||||||||a\n||||||||||||||||||||||||||||||||||||a\\h((\\((P|PPhhpp\\P|||aaaaaaaaa||||||||||||||\n|||||||||||||||||||||||||||||||||||(hhhPhha|PX|aa|\\;;\\\\P|aaaaaaaaaaaa||||aa|||aa\n|||||||||||||||||||||||||||||||||h(h((PPP|||Xp(Pa|P(p\t\t\\P|aaaaaaaaaaaaa|aaaaaaaa\n||||||||||||||||||||||||||(\\hP(XhhhhhPh|P|aa|\\aP|||P;\t\t\th||aaaaaaaaaaaaaaaaaaaa|\n|||||||||||||||||||||||||aa|aPP||Phh((hha\\aaaaa|hP||(X;pP|aaaaaaaaaaaaaaaaaaaaaa\n||||||||||||||||||||||||aaaa|PhPhhhhh(P((ha|a|PPPPa|hP(\\|aaaaaaaaaaaaaaa|aaaaaaa\n||P|P|PP|P|||P|||||||||aaaa||||PPPPPPP(PPh(h(a|;aPPPhP||aaaaaaaaaaaaaaaaaaaaaaaa\nP|PPPPPPPPPP|||P|||P|P|aaaa||||XX;\\||PPPPhhXh(hah(P;hPPaaaaaaa|a||aaaaaaaaaaa|aa\nPPPP|PPPP|PPPPPPPPPPP|||aa|a||||||X|||PPPPPhPhPPP|(P|(aaaaa|||;X;;||||||||aaaaaa\nPPPPPPPPPPPPPPPPPPPP|a||aaa||||||||||||||||P|PhP((hh|PaaaaaPPp(hP|(\\XXppp\\||aaaa\n");

		sbui.append((char)(9+10-21+12));
		
		
		sbuf.append(amazin_Gline(false));
		sbuf.append("XXX\\\\\\\\\\(\\\\\\\\((((((hPP|||aaaa|a;X;X\\X;p\tpp;(((\\(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
		sbui.append(amazin_Gline(true));
		sbuf.append("\nXXX\\\\\\X\\X\\\\\\\\\\\\\\\\\\\\\\(((hPP|||aaaaaaaaaaaah((\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\(\\\\\\\\\\\\\\(\\\\(\\\\");
		// Marked for deprecated?? But I want toString, it's essential!
		sbui.append("XXXXXXXXXXXXXXXXXXXXXX\\XX\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\X\\X\\\\\\X\\X\\X\\\\\\X\\\\\\\\\\\\\\\\X\\\\\\\\\\\\\\\\\\\\" + (new Character('\n')).toString() + "XXXXXXXXXXXXXXXXXXXXXXXXX\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\X\\\\\\\\\\XXXXXXXX\\\\XX\\X\\X\\\\\\\\\\\\XX\\X\\\\X\\\\\\XX");
		s += sbuf.toString();
		s += sbui.toString();
		s += "\nXXXXXXXXXXXXXXXXXXXXXXXX\\\\\\\\\\\\\\\\\\\\\\\\\\\\XXX\\X\\X\\XX\\XXXXXXXXX\\\\\\XXXXX\\X\\\\\\X\\XXX\\\\X\\";
		String stringToPrintIntoTheStandardOutput = makeStringToPrint(s, (c) -> {
			// TODO (totally not left here on purpose :trold:
			HashMap<Character, Integer> m = new HashMap<>();
			m.put('|', 124);
			m.put('a', 97);
					m.put('h', 104);
							m.put('P', 80);
									m.put(';', 59);
											m.put('\\', 92);
													m.put('X', 88);
															m.put('p', 112);
																	m.put('\t', 9);
			Optional<Character> cc = m.keySet().stream().filter((key) -> key == c).findFirst();
			if (c == '\n')
				return (char)10;
			if (!cc.isPresent() || cc.isEmpty()) {

				
				
				
				
				
				
				
				return c;
			}
			else if (cc.isPresent() && !cc.isEmpty()) {
				switch (m.get(cc.get())) {
				
				case 124:
					return '&';
				case 97:
					return '@';
				case 104: return '#';
				case 80: return '%';
				case 59:
					return ",".toCharArray()[0];
				case 92:
					return '/';
					case 88: return '*';
					case 112:
				return '.';
					default:
						if (c == '\t') return ' ';
			return c;
				}
			}
			return null;
		});
		System.out.println(stringToPrintIntoTheStandardOutput);
	}
}

// totally not left here on purpose either
// | -> &
// a -> @
// h -> #
// P -> %
// ; -> ,
// \\ -> /
// X -> *
// p -> .
// \t -> ' '