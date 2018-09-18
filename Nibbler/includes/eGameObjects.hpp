/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eGameObjects.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14/22/25 by cpauwels          #+#    #+#             */
/*   Updated: 2018/09/03 14/22/25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EGAMEOBJECTS_HPP
# define EGAMEOBJECTS_HPP

enum GameObject
{
    NOTHING = 0,
    BOUNDRY = 1,
    FOOD = 2,
    SNAKE_HEAD = 3,
    SNAKE_BODY = 4,
    SPECIAL_FOOD = 5
};

#endif