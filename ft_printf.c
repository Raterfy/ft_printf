/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:24:21 by robhak            #+#    #+#             */
/*   Updated: 2023/05/15 13:48:23 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_function.h"

int ft_putchar(char c)
{
    return write(1, &c, 1); // Écrit un seul caractère sur la sortie standard
}

//Cette fonction écrit un seul caractère sur la sortie standard 
//(généralement la console) en utilisant la fonction système write.

int ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
        ft_putchar(s[i++]); // Écrit chaque caractère de la chaîne sur la sortie standard
    return i; // Retourne la longueur de la chaîne écrite
}
//Cette fonction écrit une chaîne de caractères sur la sortie standard en utilisant la fonction ft_putchar. 
//Elle retourne la longueur de la chaîne écrite.

int ft_putnbr(int n)
{
    int count = 0;
    if (n < 0)
    {
        ft_putchar('-'); // Ajoute le signe moins pour les nombres négatifs
        count++;
        n = -n;
    }
    if (n >= 10)
        count += ft_putnbr(n / 10); // Appelle la fonction récursivement pour écrire chaque chiffre
    ft_putchar(n % 10 + '0'); // Écrit le chiffre de droite
    count++;
    return count; // Retourne le nombre de chiffres écrits
}
//Cette fonction écrit un entier sur la sortie standard en utilisant 
//la fonction ft_putchar. Elle gère également les nombres négatifs en ajoutant 
//un signe moins et utilise une récursion pour écrire chaque chiffre.

int ft_putnbr_base(unsigned int n, char *base)
{
    int count = 0;
    int base_len = 0;
    while (base[base_len])
        base_len++; // Calcule la longueur de la base
    if (n >= (unsigned int)base_len)
        count += ft_putnbr_base(n / base_len, base); // Appelle la fonction récursivement pour écrire chaque chiffre
    ft_putchar(base[n % base_len]); // Écrit le chiffre dans la base correspondante
    count++;
    return count; // Retourne le nombre de chiffres écrits
}
//Cette fonction écrit un entier non signé dans une base spécifiée sur la sortie standard en utilisant la fonction ft_putchar. 
//Elle utilise également une récursion pour écrire chaque chiffre.

int ft_printf(const char *format, ...)
{
    va_list args;           // déclaration d'un objet va_list pour stocker les arguments variables
    va_start(args, format); // initialisation de l'objet va_list avec le dernier argument fixe
    int i = 0;              // initialisation d'un compteur pour parcourir le format
    int count = 0;          // initialisation d'un compteur pour le nombre de caractères affichés
    while (format[i])       // tant que le format n'a pas été entièrement parcouru
    {
        if (format[i] == '%')   // si on rencontre un caractère '%'
        {
            i++;                // on passe au caractère suivant après '%'
            if (format[i] == 'c')    // si le caractère qui suit '%' est 'c'
                count += ft_putchar(va_arg(args, int));    // on affiche le caractère suivant les spécifications de 'c'
            else if (format[i] == 's')  // si le caractère qui suit '%' est 's'
                count += ft_putstr(va_arg(args, char *)); // on affiche la chaîne de caractères suivant les spécifications de 's'
            else if (format[i] == 'p')  // si le caractère qui suit '%' est 'p'
            {
                count += ft_putstr("0x");   // on affiche le préfixe '0x'
                count += ft_putnbr_base((unsigned long)va_arg(args, void *), "0123456789abcdef");   // on affiche l'adresse pointée en hexadécimal
            }
            else if (format[i] == 'd' || format[i] == 'i')    // si le caractère qui suit '%' est 'd' ou 'i'
                count += ft_putnbr(va_arg(args, int));    // on affiche le nombre suivant les spécifications de 'd' ou 'i'
            else if (format[i] == 'u')  // si le caractère qui suit '%' est 'u'
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");   // on affiche le nombre suivant les spécifications de 'u'
            else if (format[i] == 'x')  // si le caractère qui suit '%' est 'x'
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");   // on affiche le nombre suivant les spécifications de 'x'
            else if (format[i] == 'X')  // si le caractère qui suit '%' est 'X'
                count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");   // on affiche le nombre suivant les spécifications de 'X'
            else if (format[i] == '%')  // si le caractère qui suit '%' est '%'
                count += ft_putchar('%');   // on affiche un '%'
        }
        else    // si on rencontre un caractère différent de '%'
            count += ft_putchar(format[i]); // on l'affiche tel quel
        i++;    // on passe au caractère suivant
    }
    va_end(args);   // libération des ressources allouées à l'objet va_list
    return count;   // on renvoie le nombre de caractères affichés
}