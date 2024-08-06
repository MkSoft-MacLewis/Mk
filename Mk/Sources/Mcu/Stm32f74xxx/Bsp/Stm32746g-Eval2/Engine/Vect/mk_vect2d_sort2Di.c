/**
*
* @copyright Copyright (C) 2023 RENARD Mathieu. All rights reserved.
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
* @file mk_vect2d_sort2Di.c
* @brief Définition de la fonction mk_vect2d_sort2Di.
* @date 21 juin 2023
*
*/

#include "mk_engine_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_vect2d_sort2Di ( T_mkVect2Di* p_v1, T_mkVect2Di* p_v2 )
{
   /* Déclaration d'un vecteur de travail */
   T_mkVect2Di l_temp = { p_v1->x, p_v1->y };

   /* Si l'abscisse du vecteur de fin est supérieure à l'abscisse */
   /* du vecteur de début */
   if ( p_v2->x < p_v1->x )
   {
      /* Permutation des abscisses */
      p_v1->x = p_v2->x;
      p_v2->x = l_temp.x;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si l'ordonnée du vecteur de fin est inférieure à l'ordonnée */
   /* du vecteur de début */
   if ( p_v2->y < p_v1->y )
   {
      /* Permutation des ordonnées */
      p_v1->y = p_v2->y;
      p_v2->y = l_temp.y;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}




