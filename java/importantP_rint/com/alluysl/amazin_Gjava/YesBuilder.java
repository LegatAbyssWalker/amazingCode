package com.alluysl.amazin_Gjava;

import java.util.function.Function;

public final class YesBuilder {

	static Yes build() {
		Yes res = new Yes() {

			@Override
			public StringBuffer amazin_Gline(boolean which) {
				// TODO Auto-generated method stub
				which = !which;
				StringBuffer res = null;
				switch (which ? 1 : 0) {
				
				case 1:
					res = new StringBuffer("\\\\\\(\\\\\\((((hhhhPPPP||aaX;;;|PPh|PPp\t\t\t\t\t\th((((((((((((\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nX\\\\\\\\\\((((((((h(hhP|||aaa|;;;PpPPPPPhh((hPh(((\\(\\\\\\(\\\\\\\\\\\\\\\\\\\\\\\\(\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
					
				default:
					if (!which) { } else break;
					res = new StringBuffer();
					res.append("XXXXXX\\XXXXXXXXXXXXXX\\X\\X\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\X\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\X\\\\\\\\\\\\\\\\\\\\\\");
					res.append(Character.toChars(10));
					return res;
				}
				return res;
			}

			@Override
			public String makeStringToPrint(String inputString, Function<Character, Character> charMapper) {
				// TODO Auto-generated method stub
				String str = "";
				for (Character c : inputString.toCharArray())
					str += charMapper.apply(c);
				return str;
			}};
		
			if (false) {
			// | -> &
				// a -> @
			// h -> #
			// P -> %
			// ; -> ,
		// \ -> /
		// X -> *
			// p -> .
		Character[] ee = { '|', 'a', 'h', 'P', ';', '\\', 'X', 'p', '\t' };
		for (int i = 0; i < ee.length; ++i)
			System.out.println(ee[i].hashCode());}
		
		Function<Void, Void> e = res::print;
		res.printer = e;
		return res;
	}
}
