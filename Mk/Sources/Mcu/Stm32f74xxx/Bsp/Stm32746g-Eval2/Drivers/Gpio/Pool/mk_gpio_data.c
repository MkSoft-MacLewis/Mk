/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_gpio_data.c
* @brief Définition de la fonction mk_gpio_data.
* @date 23 déc. 2020
*
*/

#include "mk_gpio_api.h"

/**
 * @fn uint32_t g_mkGPIOProtectionTable [ K_MK_GPIO_NUMBER_OF_PORTS ];
 * @brief Déclaration de la table de protection des ports d'entrées-sorties.
 * @note Un niveau 1 indique une broche protégée, un niveau 0 indique une broche non protégée.
 *
 */

const uint32_t g_mkGPIOProtectionTable [ K_MK_GPIO_NUMBER_OF_PORTS ] = {

      0xFFF0FFFF, /* K_MK_GPIO_EXPANDER */
      0xFFFFFFFF, /* K_MK_GPIO_PORTA */
      0xFFFFFFFF, /* K_MK_GPIO_PORTB */
      0xFFFFFFFF, /* K_MK_GPIO_PORTC */
      0xFFFFFFFF, /* K_MK_GPIO_PORTD */
      0xFFFFFFFF, /* K_MK_GPIO_PORTE */
      0xFFFFFFFF, /* K_MK_GPIO_PORTF */
      0xFFFFFFFF, /* K_MK_GPIO_PORTG */
      0xFFFFFFFF, /* K_MK_GPIO_PORTH */
      0xFFFFFFFF, /* K_MK_GPIO_PORTI */
      0xFFFFFFFF, /* K_MK_GPIO_PORTJ */
      0xFFFFFFFF, /* K_MK_GPIO_PORTK */
};

/**
 * @fn T_mkGPIORequestArea g_mkGPIORequestArea;
 * @brief Déclaration des données relatives à la messagerie du terminal GPIO.
 *
 */

K_MK_PRIVILEGED_DMA_MEMORY T_mkGPIORequestArea g_mkGPIORequestArea;

/**
 * @fn uint32_t g_mkGPIOStackAddr;
 * @brief Déclaration de la stack du terminal GPIO.
 *
 */

K_MK_PRIVILEGED_DMA_MEMORY uint32_t g_mkGPIOStackAddr [ K_MK_GPIO_STACK_SIZE ];


