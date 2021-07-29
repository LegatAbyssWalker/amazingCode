package com.alluysl.amazin_Gjava;

import java.util.function.Function;

public abstract class Yes implements TrollFacePrinter, AmogusPrinter {

	public Function<Void, Void> printer;

	@Override
	public void print() {
		// TODO Auto-generated method stub
		AmogusPrinter.super.print();
	}
	
	public Void print(Void v) {
		print();
		return v;
	}
}
