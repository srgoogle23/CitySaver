bool verificaGameOverReinicia();

bool verificaGameOverReinicia()
{
    if(estaNoTimePosReinicial)
    {
        // incrementa contador pós game over
        gameOverReinicia++;

        if(gameOverReinicia > 60)
        {
            gameOverReinicia = 0;
            estaNoTimePosReinicial = false;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}