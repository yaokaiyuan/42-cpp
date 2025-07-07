/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:41:26 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/07/07 16:52:50 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T *array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif
