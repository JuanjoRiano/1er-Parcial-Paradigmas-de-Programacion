-- Importamos módulos necesarios para ordenar listas
import Data.List (sortBy) -- sortBy nos permite ordenar listas con un criterio personalizado
import Data.Ord (comparing) -- comparing facilita la comparación de elementos
import Control.Arrow (Arrow(first)) -- Importamos first, aunque en este código no se usa

-- Definimos un alias de tipo para mayor claridad
type Estudiante = (String, Float) -- Un estudiante es una tupla (Nombre, Calificación)

-- Función para ordenar estudiantes en orden descendente por calificación
-- En caso de empate, se ordena por nombre en orden ascendente
bubbleSortDescending :: [Estudiante] -> [Estudiante]
bubbleSortDescending = sortBy (comparing (negate . snd) <> comparing fst)
-- comparing (negate . snd)   -> Ordena primero por la segunda componente (calificación) en orden descendente
-- comparing fst              -> Si hay empate, ordena por la primera componente (nombre) en orden ascendente

-- Función principal
main :: IO()
main = do
    -- Lista de estudiantes con sus calificaciones
    let estudiantes = [("Ana", 85), ("Luis", 90), ("Carlos", 85), ("Sofia", 92), ("Maria", 90)]
    -- Aplicamos la función de ordenación e imprimimos el resultado
    print (bubbleSortDescending estudiantes)
