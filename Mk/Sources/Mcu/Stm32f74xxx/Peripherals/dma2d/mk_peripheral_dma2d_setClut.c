/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file mk_peripheral_dma2d_setClut.c
* @brief Définition de la fonction dma2d_setClut.
* @date 9 mars 2019
*
*/

#include "mk_peripheral_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void dma2d_setClut ( void_t p_target, uint32_t* p_baseAddr, uint32_t p_format, uint32_t p_size )
{
   /* Ecriture des registres DMA2D_FGPFCCR ou DMA2D_BGPFCCR */
   _writeField ( p_target, 0x00000010, p_format );
   _putField ( p_target, 0x000000FF, ( p_size - 1 ), 8 );

   /* Si configuration du FPC de premier plan */
   if ( p_target == K_DMA2D_PFC_FOREGROUND )
   {
      /* Ecriture du registre DMA2D_FGCMAR */
      _writeWord ( K_DMA2D_FGCMAR, ( uint32_t ) p_baseAddr );
   }

   /* Sinon */
   else
   {
      /* Ecriture du registre DMA2D_FGCMAR */
      _writeWord ( K_DMA2D_BGCMAR, ( uint32_t ) p_baseAddr );
   }

   /* Retour */
   return;
}


