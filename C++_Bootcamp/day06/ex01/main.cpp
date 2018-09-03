/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:52:14 by cpauwels          #+#    #+#             */
/*   Updated: 2018/06/12 11:52:15 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct SerializeData
{
    char s1[9];
    int n;
    char s2[9];
};

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void randomise(char * s)
{
    int i = 0;
    while (i < 8)
    {
        while (!isalnum(s[i]))
            s[i] = (char)((rand() % 74) + 48);
        i++;
    }
    s[i] = '\0';
}

void * serialize(void)
{
    SerializeData * ser = new SerializeData;

    randomise(ser->s1);
    ser->n = rand() % 9 + 48;
    randomise(ser->s2);
    return reinterpret_cast<void *>(ser);
}

Data * deserialize(void * raw)
{
    SerializeData * ser = new SerializeData;
    Data * data = new Data;

    ser = reinterpret_cast<SerializeData *>(raw);
    data->s1 = static_cast<std::string>(ser->s1);
    data->n = ser->n;
    data->s2 = static_cast<std::string>(ser->s2);
    return data;
}

int main()
{
    void *  tmp;
    Data *  ptr;

    srand(time(NULL));
    tmp = serialize();
    ptr = deserialize(tmp);
    std::cout << ptr->s1 << std::endl;
    std::cout << ptr->n << std::endl;
    std::cout << ptr->s2 << std::endl; 
    return 0;   
}
