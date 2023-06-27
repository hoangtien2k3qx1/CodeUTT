/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai1;

import java.io.Serializable;

/**
 *
 * @author hoang
 */
class Person implements Serializable {
    private String fullName;
    private String birthDate;
    private String address;
    private String gender;

    public Person(String fullName, String birthDate, String address, String gender) {
        this.fullName = fullName;
        this.birthDate = birthDate;
        this.address = address;
        this.gender = gender;
    }

    public void displayInfo() {
        System.out.println("Full Name: " + fullName);
        System.out.println("Birth Date: " + birthDate);
        System.out.println("Address: " + address);
        System.out.println("Gender: " + gender);
    }
}
