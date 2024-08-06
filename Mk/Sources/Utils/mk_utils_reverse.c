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
* @file mk_utils_reverse.c
* @brief Définition de la fonction mk_utils_reverse.
* @date 1 janv. 2020
*
*/

#include "mk_utils_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_utils_reverse ( T_str8 p_str, uint32_t p_length )
{
   /* Déclaration des variables de travail */
   uint32_t l_start = 0;
   uint32_t l_end   = p_length - 1;
   int8_t   l_tmp   = 0;

   /* Tant que la chaine n'est pas entièrement permutée */
   while ( l_start < l_end)
   {
      /* Enregistrement du caractère courant */
      l_tmp = * ( p_str + l_end );

      /* Echange */
      * ( p_str + l_end )   = * ( p_str + l_start );
      * ( p_str + l_start ) =   ( l_tmp );

      /* Actualisation des variables */
      l_start++;
      l_end--;
   }

   /* Retour */
   return;
}


